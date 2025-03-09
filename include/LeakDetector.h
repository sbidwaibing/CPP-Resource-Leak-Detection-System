// include/LeakDetector.h
#ifndef LEAK_DETECTOR_H
#define LEAK_DETECTOR_H
#include <string>  // Add this to include std::string
class LeakDetector {
public:
    // Method to detect memory leaks by checking if unfreed objects exist
    static void detectLeaks();

    // Register an object for memory leak detection
    static void registerObject(void* object, const std::string& className);
};

#endif
