cmake_minimum_required(VERSION 3.0)
project(Tutorial)

# Version numbers are better at the beginning.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Option for using our own amth function.
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# Configure a header file to pass in the CMake settings to the source code.
configure_file(
  "${PROJECT_SOURCE_DIR}/TutorialConfig.hpp.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.hpp"
)

# Add the binary tree to the search path so we can include that header.
include_directories("${PROJECT_BINARY_DIR}")

# The math library, but it may be optional.
if (USE_MYMATH)
  include_directories("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory(MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


# Add the executable (this usually goes near the end)
add_executable(Tutorial tutorial.cpp)

# Link everything together.
target_link_libraries(Tutorial ${EXTRA_LIBS})

