// src/ReferenceTracker.cpp
#include "ReferenceTracker.h"
#include <iostream>

std::unordered_map<void*, std::string> ReferenceTracker::objectReferences;

void ReferenceTracker::trackObject(void* object, const std::string& className) {
    objectReferences[object] = className;
    std::cout << "Tracked object of type '" << className << "' at " << object << std::endl;
}

void ReferenceTracker::releaseObject(void* object) {
    objectReferences.erase(object);
    std::cout << "Released object at " << object << std::endl;
}

bool ReferenceTracker::isObjectTracked(void* object) {
    return objectReferences.find(object) != objectReferences.end();
}

void ReferenceTracker::printTrackedObjects() {
    for (const auto& entry : objectReferences) {
        std::cout << "Object of type '" << entry.second << "' at address " << entry.first << std::endl;
    }
}
