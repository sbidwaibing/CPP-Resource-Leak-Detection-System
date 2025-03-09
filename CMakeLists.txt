cmake_minimum_required(VERSION 3.10)

project(MLD_Library VERSION 1.0)

# Add Google Test as a subdirectory
add_subdirectory(googletest)

# Include directories for the project
include_directories(${PROJECT_SOURCE_DIR}/include)

# Add source files for the main project
add_executable(mld_library
    src/ReferenceTracker.cpp
    src/LeakDetector.cpp
    src/ResourceManager.cpp
    tests/ReferenceTrackerTest.cpp
)

# Link Google Test with your project
target_link_libraries(mld_library gtest gtest_main)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Enable testing
enable_testing()

# Add the test
add_test(NAME ReferenceTrackerTest COMMAND mld_library)
