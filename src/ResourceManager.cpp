// src/ResourceManager.cpp
#include "ResourceManager.h"
#include <iostream>
#include <unistd.h>
#include <sys/mman.h>

void ResourceManager::trackResource(void* resource, const std::string& resourceName) {
    std::cout << "Tracking resource: " << resourceName << " at " << resource << std::endl;
}

void ResourceManager::releaseResource(void* resource) {
    std::cout << "Released resource at " << resource << std::endl;
}

// Track and release file handles
void ResourceManager::trackFileHandle(FILE* fileHandle, const std::string& resourceName) {
    std::cout << "Tracking file handle: " << resourceName << " at " << fileHandle << std::endl;
}

void ResourceManager::releaseFileHandle(FILE* fileHandle) {
    std::cout << "Released file handle at " << fileHandle << std::endl;
    fclose(fileHandle);  // Closing the file handle
}

// Track and release sockets
void ResourceManager::trackSocket(int socket, const std::string& resourceName) {
    std::cout << "Tracking socket: " << resourceName << " at " << socket << std::endl;
}

void ResourceManager::releaseSocket(int socket) {
    std::cout << "Released socket at " << socket << std::endl;
    close(socket);  // Closing the socket
}

// Track and release shared memory
void ResourceManager::trackSharedMemory(void* memory, const std::string& resourceName) {
    std::cout << "Tracking shared memory: " << resourceName << " at " << memory << std::endl;
}

void ResourceManager::releaseSharedMemory(void* memory) {
    std::cout << "Released shared memory at " << memory << std::endl;
    munmap(memory, sizeof(memory));  // Unmapping shared memory
}

// Track and release custom resources (e.g., objects from third-party libraries)
void ResourceManager::trackCustomResource(void* resource, const std::string& resourceName) {
    std::cout << "Tracking custom resource: " << resourceName << " at " << resource << std::endl;
}

void ResourceManager::releaseCustomResource(void* resource) {
    std::cout << "Released custom resource at " << resource << std::endl;
    // Custom cleanup code for specific resources can be added here
}