// A "simple" program that builds a sqrt table.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
using std::endl;
using std::cout;
using std::ofstream;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 1;
  }
  
  int i;
  double result;

  ofstream outFile;
  outFile.open(argv[1]);
  if (!outFile.is_open()) {
    return 1;
  }
  
  // create a source file with a table of square roots.
  outFile << "double sqrtTable[] = {" << endl;
  for (i = 0; i < 10; ++i) {
    result = sqrt(static_cast<double>(i));
    outFile << result << "," << endl;
  }

  // Place a zero at the end.
  outFile << 0 << "};" << endl;
  outFile.close();
  return 0;
}
