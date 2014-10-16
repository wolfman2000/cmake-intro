#include <iostream>
#include "MathFunctions.hpp"
using std::cout;
using std::endl;

// "hack" square root calculation with simple operations.
double mysqrt(double x) {
  if (x <= 0) {
    return 0;
  }

  double result = x;
  double delta;

  for (int i = 0; i < 10; ++i) {
    if (result <= 0) {
      result = 0.1;
    }
    delta = x - (result * result);
    result = result + 0.5 * delta / result;
    
    cout << "Computing sqrt of " << x << " to be " << result << endl;
  }

  return result;
}
