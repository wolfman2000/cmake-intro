# Add the binary tree directory to the search path for the include files.
include_directories(${CMAKE_CURRENT_BINARY_DIR})

# We'll need the executable to generate a table.
add_executable(MakeTable makeTable.cpp)

# Add the command to generate the source code.
add_custom_command(
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.hpp
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.hpp
  DEPENDS MakeTable
)
 
add_library(MathFunctions mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.hpp)

# For installation purposes, get the files in the right place.
install(TARGETS MathFunctions DESTINATION bin)
install(FILES MathFunctions.hpp DESTINATION include)

