// A simple program that computes the square root of a number.

#include <iostream>
#include <cmath>
#include "TutorialConfig.hpp"
using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << argv[0] << " Version " << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << endl;
    cout << "Usage: " << argv[0] << " number" << endl;
    return 1;
  }

  double inputValue = atof(argv[1]);
  double outputValue = sqrt(inputValue);

  cout << "The square root of " << inputValue << " is " << outputValue << endl;

  return 0;
}
