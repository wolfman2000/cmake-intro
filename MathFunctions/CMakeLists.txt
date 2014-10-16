add_library(MathFunctions mysqrt.cpp)

# For installation purposes, get the files in the right place.
install(TARGETS MathFunctions DESTINATION bin)
install(FILES MathFunctions.hpp DESTINATION include)

