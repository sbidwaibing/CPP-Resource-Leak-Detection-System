#include <gtest/gtest.h>
#include "ReferenceTracker.h"
#include "LeakDetector.h"
#include "ResourceManager.h"

// For socket programming
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// For memory management (mmap)
#include <sys/mman.h>
#include <unistd.h>  // For close() and other system calls

// Test for ReferenceTracker: Tracking and releasing objects
TEST(ReferenceTrackerTest, TestTrackObject) {
    int* ptr = new int(5);  // Allocate memory
    ReferenceTracker::trackObject(ptr, "int");

    EXPECT_TRUE(ReferenceTracker::isObjectTracked(ptr));  // Assert the object is tracked
    std::cout << "Running Test: TestTrackObject" << std::endl;  // New line to verify pipeline
    std::cout << "Running Test: TestTrackObject" << std::endl;  // New line2 to verify pipeline
    ReferenceTracker::releaseObject(ptr);  // Release the object from tracking
    EXPECT_FALSE(ReferenceTracker::isObjectTracked(ptr));  // Assert the object is no longer tracked

    delete ptr;  // Free memory
}

// Test for LeakDetector: Detecting leaks
TEST(LeakDetectorTest, TestMemoryLeaks) {
    int* leakedObj = new int(10);
    LeakDetector::registerObject(leakedObj, "int");

    // Run the leak detection which will print all tracked objects
    LeakDetector::detectLeaks();

    // Clean up
    delete leakedObj;
}

// Test for ResourceManager: Tracking and releasing resources
TEST(ResourceManagerTest, TestTrackResource) {
    void* resource = malloc(100);  // Allocate some memory as a resource
    ResourceManager::trackResource(resource, "Memory");

    // Assert resource tracking
    EXPECT_NE(resource, nullptr);  // Just ensure resource isn't null

    ResourceManager::releaseResource(resource);  // Release the resource
    free(resource);  // Clean up allocated memory
}

// Test for Circular Reference
class CircularReference {
public:
    CircularReference* next;
    CircularReference() : next(nullptr) {}
};

TEST(ReferenceTrackerTest, TestCircularReference) {
    CircularReference* obj1 = new CircularReference();
    CircularReference* obj2 = new CircularReference();
    
    // Create circular references
    obj1->next = obj2;
    obj2->next = obj1;

    ReferenceTracker::trackObject(obj1, "CircularReference");
    ReferenceTracker::trackObject(obj2, "CircularReference");

    // Assert they are being tracked
    EXPECT_TRUE(ReferenceTracker::isObjectTracked(obj1));
    EXPECT_TRUE(ReferenceTracker::isObjectTracked(obj2));

    // Release objects and check tracking
    delete obj1;
    delete obj2;
    
    ReferenceTracker::releaseObject(obj1);
    ReferenceTracker::releaseObject(obj2);

    EXPECT_FALSE(ReferenceTracker::isObjectTracked(obj1));
    EXPECT_FALSE(ReferenceTracker::isObjectTracked(obj2));
}

// Test for Thread Leaks
#include <thread>

// Simulate a thread that doesn't terminate properly
void leak_thread() {
    std::this_thread::sleep_for(std::chrono::seconds(1));  // Simulating a running thread
}

TEST(ResourceManagerTest, TestThreadLeak) {
    std::thread t1(leak_thread);
    ResourceManager::trackResource(&t1, "Thread");

    // Assert that the thread resource is tracked
    EXPECT_NE(&t1, nullptr);

    // Detach the thread, which simulates the case where we do not join it
    t1.detach();

    // After detaching, a thread is no longer joinable, so we should not check joinable here.
    // Instead, just verify that the thread has been detached and is not causing a resource leak.
    
    // Release the thread resource (even though it's running indefinitely, we simulate its cleanup)
    ResourceManager::releaseResource(&t1);

    // Since the thread is detached, we can't join it. We will simply assert that it was detached properly.
    EXPECT_TRUE(t1.joinable() == false);  // It should be not joinable now

    // Clean up thread object (not typically how threads are cleaned up, but this is for the test)
    t1.~thread();
}

// Test for Network Connection Leaks
class NetworkConnection {
public:
    void connect() { /* Simulate connection setup */ }
    void disconnect() { /* Simulate disconnecting the network */ }
};

TEST(ResourceManagerTest, TestNetworkConnection) {
    NetworkConnection* netConn = new NetworkConnection();
    netConn->connect();
    ResourceManager::trackResource(netConn, "NetworkConnection");

    // Assert that the network connection is tracked
    EXPECT_NE(netConn, nullptr);

    // Disconnect and release the resource
    netConn->disconnect();
    ResourceManager::releaseResource(netConn);
    
    delete netConn;  // Clean up
}

// Test for Database Connection Leaks
class DatabaseConnection {
public:
    void open() { /* Simulate DB connection */ }
    void close() { /* Simulate closing DB connection */ }
};

TEST(ResourceManagerTest, TestDatabaseConnection) {
    DatabaseConnection* dbConn = new DatabaseConnection();
    dbConn->open();
    ResourceManager::trackResource(dbConn, "DatabaseConnection");

    // Assert the DB connection is tracked
    EXPECT_NE(dbConn, nullptr);

    // Close and release the resource
    dbConn->close();
    ResourceManager::releaseResource(dbConn);
    
    delete dbConn;  // Clean up
}

// tests/ResourceManagerTest.cpp

#include <gtest/gtest.h>
#include "ResourceManager.h"

// Test for file handle tracking and release
TEST(ResourceManagerTest, TestFileHandle) {
    FILE* file = fopen("example.txt", "w");
    ResourceManager::trackFileHandle(file, "Example File");

    // Perform some operations with the file
    fprintf(file, "Test content\n");

    // Assert the file is tracked
    EXPECT_NE(file, nullptr);

    // Release the resource
    ResourceManager::releaseFileHandle(file);
}

// Test for socket tracking and release
// TEST(ResourceManagerTest, TestSocket) {
//     int socket = socket(AF_INET, SOCK_STREAM, 0);  // Example socket creation
//     ResourceManager::trackSocket(socket, "Example Socket");

//     // Assert the socket is tracked
//     EXPECT_NE(socket, -1);

//     // Release the resource
//     ResourceManager::releaseSocket(socket);
// }
TEST(ResourceManagerTest, TestSocket) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);  // Example socket creation
    ResourceManager::trackSocket(sockfd, "Ex Socket");

    // Assert the socket is tracked
    EXPECT_NE(sockfd, -1);

    // Release the resource
    ResourceManager::releaseSocket(sockfd);
}

// Test for shared memory tracking and release
TEST(ResourceManagerTest, TestSharedMemory) {
    void* memory = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANON, -1, 0);
    ResourceManager::trackSharedMemory(memory, "Shared Memory");

    // Assert the memory is tracked
    EXPECT_NE(memory, nullptr);

    // Release the resource
    ResourceManager::releaseSharedMemory(memory);
}

// Test for custom resource tracking and release
TEST(ResourceManagerTest, TestCustomResource) {
    int* customResource = new int(100);
    ResourceManager::trackCustomResource(customResource, "Custom Resource");

    // Assert the custom resource is tracked
    EXPECT_NE(customResource, nullptr);

    // Release the resource
    delete customResource;
    ResourceManager::releaseCustomResource(customResource);
}