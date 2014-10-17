cmake_minimum_required(VERSION 3.0)
project(Tutorial)

# Version numbers are better at the beginning.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# Option for using our own amth function.
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# Does the system have log and exp math functions?
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake) # Built-in functionality?
check_function_exists(log HAVE_LOG)
check_function_exists(exp HAVE_EXP)

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

# Set up the install targets.
install (TARGETS Tutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.hpp" DESTINATION include)

# Don't forget to include some tests.
enable_testing()

# Does the application run?
add_test(TutorialRuns Tutorial 25)

# Utilize a macro for multiple tests of the same type.
macro (do_test arg result)
  add_test(TutorialComp${arg} Tutorial ${arg})
  set_tests_properties (TutorialComp${arg} PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro(do_test)

# Can it compute the sqrt of 25 correctly?
do_test(25 "25 is 5")

# Can it handle negative numbers?
do_test(-25 "-25 is 0")

# Can it handle small numbers?
do_test(0.0001 "0.0001 is 0.01")

# Does the usage message work?
add_test (TutorialUsage Tutorial)
set_tests_properties(TutorialUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number")

# CMake can make an installer package driven by CPack.
include(InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")
include (CPack)

