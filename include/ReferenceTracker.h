// include/ReferenceTracker.h
#ifndef REFERENCE_TRACKER_H
#define REFERENCE_TRACKER_H

#include <unordered_map>
#include <string>

class ReferenceTracker {
public:
    // Tracks an object allocation
    static void trackObject(void* object, const std::string& className);

    // Releases the object from tracking
    static void releaseObject(void* object);

    // Checks if an object is being tracked
    static bool isObjectTracked(void* object);

    // Prints all tracked objects (for debugging)
    static void printTrackedObjects();

private:
    static std::unordered_map<void*, std::string> objectReferences;
};

#endif
