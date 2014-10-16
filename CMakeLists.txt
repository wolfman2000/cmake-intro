cmake_minimum_required(VERSION 3.0)
project(Tutorial)

# Version numbers are better at the beginning.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Configure a header file to pass in the CMake settings to the source code.
configure_file(
  "${PROJECT_SOURCE_DIR}/TutorialConfig.hpp.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.hpp"
)

# Add the binary tree to the search path so we can include that header.
include_directories("${PROJECT_BINARY_DIR}")

# Add the executable (this usually goes near the end)
add_executable(Tutorial tutorial.cpp)

