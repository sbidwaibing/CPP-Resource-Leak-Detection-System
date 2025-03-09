# CMake generated Testfile for 
# Source directory: /Users/sukrutrahulbidwai/Downloads/CPP-Memory-Leak-Detection-Lib-main
# Build directory: /Users/sukrutrahulbidwai/Downloads/CPP-Memory-Leak-Detection-Lib-main/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(ReferenceTrackerTest "/Users/sukrutrahulbidwai/Downloads/CPP-Memory-Leak-Detection-Lib-main/build/mld_library")
set_tests_properties(ReferenceTrackerTest PROPERTIES  _BACKTRACE_TRIPLES "/Users/sukrutrahulbidwai/Downloads/CPP-Memory-Leak-Detection-Lib-main/CMakeLists.txt;30;add_test;/Users/sukrutrahulbidwai/Downloads/CPP-Memory-Leak-Detection-Lib-main/CMakeLists.txt;0;")
subdirs("googletest")
