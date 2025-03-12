# C++ Resource Leak Detection System

### Description:
### Resource & Memory leak is a common issue in low-level programming languages like C++ where developers manually manage memory. In large-scale projects, these leaks can lead to performance degradation, crashes, or unpredictable behavior. This project aims to provide a C++ Resource Leak Detection System that helps developers track and identify application resource leaks.

#### The library provides an easy way to:
- Track object allocations and deallocations
- Monitor resource usage (e.g., file handles, database connections)
- Detect memory leaks by identifying unfreed objects
- Automatically clean up and release resources

```
The main motivation for this project is to offer a simple, reusable solution for automatically detecting memory and resource leaks during development and testing, improving the reliability of C++ applications.
```

> [!NOTE]
> This project is developed in C++ and utilizes Google Test for unit testing to ensure robustness and reliability.

#### Key Features Implemented:
1. Object Tracking: Tracks memory allocations and deallocations, ensuring that every object created is properly freed.
2. Memory Leak Detection: Identifies memory leaks by checking unfreed objects after program termination.
3. Resource Management: Monitors resources such as file handles, database connections, and network sockets, ensuring proper cleanup after use.
4. Unit Testing with Google Test: Implements Google Test framework for unit testing to verify the functionality of the memory leak detection and resource management features.
5. Cross-Platform Compatibility: This library is designed to work across different platforms, such as Linux, macOS, and Windows.

#### How This Project Runs

```
Setup and Build:
To build and run this project, follow these steps:

$ git clone https://github.com/sbidwaibing/CPP-Resource-Leak-Detection-System.git
$ cd MLD_Library_Structures
```
Note: if the build directory is already present please continue with the **command 
else use the below one ->

```
Create a build directory:
$ mkdir build
```
```
change directory to build:
** $cd build
```
```
Run CMake to configure the project:
$ cmake ..
```
```
Build the project using Make:
$ make
```
```
Run the tests:
$ ./mld_library
```

#### Commands Overview:
1. cmake ..: Configures the project for building.
2. make: Compiles the project using the Make build system.
3. ./mld_library: Runs the executable, which triggers unit tests and outputs results to the terminal.

#### Google Test for Unit Testing
Google Test is used in this project to perform unit testing on key components of the library, such as Object Tracking, Memory Leak Detection, and Resource Management.

#### How Google Test is Integrated:
Cloning Google Test: The Googletest repository is cloned directly into the project, allowing easy integration without relying on external package managers like vcpkg.
- Writing Test Cases: Test cases for the ReferenceTracker, LeakDetector, and ResourceManager classes are written using Google Test.
- Running Tests: The tests are compiled and run as part of the project’s build process. The mld_library executable is built, which automatically runs the tests during execution.

#### Test Results:
The tests include various checks:
1. Object tracking: Verifies that objects are properly tracked during allocation and deallocation.
2. Memory leak detection: Ensures that unfreed objects are flagged correctly.
3. Resource management: Confirms that resources like database connections, file handles, and network connections are managed and released correctly.

#### After running the tests, you will see results like:
```
OUTPUT:
[ RUN      ] ReferenceTrackerTest.TestTrackObject
Tracked object of type 'int' at 0x159607740
Released object at 0x159607740
[       OK ] ReferenceTrackerTest.TestTrackObject

[ RUN      ] LeakDetectorTest.TestMemoryLeaks
Detecting memory leaks...
Object of type 'int' at address 0x159607740
[       OK ] LeakDetectorTest.TestMemoryLeaks

[ RUN      ] ResourceManagerTest.TestTrackResource
Tracking resource: Memory at 0x1597041a0
Released resource at 0x1597041a0
[       OK ] ResourceManagerTest.TestTrackResource
```
These results confirm that the tests were successful and that the memory leak detection library works as expected.

#### Conclusion
This project provides a lightweight, easy-to-use solution for tracking and identifying memory leaks and resource mismanagement in C++ applications. With its integration with Google Test, the library ensures that its features are thoroughly tested and reliable. The project helps developers keep their C++ code base efficient, stable, and free from memory-related bugs.

> [!TIP]
> Feel free to contribute, report bugs, or suggest improvements by opening an issue or creating a pull request on GitHub.

> [!IMPORTANT]
> For questions or inquiries, you can reach me at [Gmail](s.bidwai2000@gmail.com).

> [!CAUTION]
> This project is licensed under the MIT License - see the LICENSE file for details.
