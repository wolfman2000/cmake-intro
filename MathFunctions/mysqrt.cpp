#include <iostream>
#include "MathFunctions.hpp"
#include "TutorialConfig.hpp"

// Don't forget the generated table.
#include "Table.hpp"

using std::cout;
using std::endl;

// "hack" square root calculation with simple operations.
double mysqrt(double x) {
  if (x <= 0) {
    return 0;
  }

  double result = x;
  
  if (x >= 1 && x < 10) {
    result = sqrtTable[static_cast<int>(x)];
  }
  else {
    double delta;

    for (int i = 0; i < 10; ++i) {
      if (result <= 0) {
        result = 0.1;
      }
      delta = x - (result * result);
      result = result + 0.5 * delta / result;
      
      cout << "Computing sqrt of " << x << " to be " << result << endl;
    }
  }
  return result;
}
