#include "axis.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
  // Create AXIS instance
  AXIS axis(argc, argv);

  // Run main and get exit code
  const int exitCode = axis.run();

  // Return code
  return exitCode;
}

// Main controlling method. Calls everything else.
int AXIS::run() {

  return EXIT_SUCCESS;
}
