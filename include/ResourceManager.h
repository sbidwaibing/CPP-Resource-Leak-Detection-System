// include/ResourceManager.h
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <string>

class ResourceManager {
public:
    // Existing methods
    static void trackResource(void* resource, const std::string& resourceName);
    static void releaseResource(void* resource);

    // New methods for additional resources
    static void trackFileHandle(FILE* fileHandle, const std::string& resourceName);
    static void releaseFileHandle(FILE* fileHandle);

    static void trackSocket(int socket, const std::string& resourceName);
    static void releaseSocket(int socket);

    static void trackSharedMemory(void* memory, const std::string& resourceName);
    static void releaseSharedMemory(void* memory);

    static void trackCustomResource(void* resource, const std::string& resourceName);
    static void releaseCustomResource(void* resource);
};

#endif