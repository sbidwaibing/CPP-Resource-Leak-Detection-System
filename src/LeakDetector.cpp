// src/LeakDetector.cpp
#include "LeakDetector.h"
#include "ReferenceTracker.h"
#include <iostream>

void LeakDetector::detectLeaks() {
    std::cout << "Detecting memory leaks..." << std::endl;
    ReferenceTracker::printTrackedObjects();  // Print objects that are still tracked
}

void LeakDetector::registerObject(void* object, const std::string& className) {
    ReferenceTracker::trackObject(object, className);  // Register object for tracking
}
