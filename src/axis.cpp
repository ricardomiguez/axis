#include "axis.h"

#include <cstdlib>
#include <iostream>
#include "environment.h"

Environment* mEnvironment = nullptr;

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

  // Print to check execution
  std::cout << "Running AXIS::run()..." << std::endl;

  Environment::m_argc = m_argc;
  Environment::m_argv = m_argv;

  // Create environment
  mEnvironment = new Environment(m_argc, m_argv);

  // Delete envrionment
  if(mEnvironment != nullptr) {
    delete mEnvironment;
    mEnvironment = nullptr;
  }

  // Print to check execution
  std::cout << "Finalizing AXIS::run()." << std::endl;

  return EXIT_SUCCESS;
}
