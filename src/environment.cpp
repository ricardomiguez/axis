#include "environment.h"

#include <iostream>
#include "application.h"
// The environment rads the name of the property file and createa new mApplicaton

int Environment::m_argc;
char** Environment::m_argv;

// Environment constructor
Environment::Environment(int argc, char** argv) {
  Environment::m_argc = argc;
  Environment::m_argv = argv;

  // TODO @rodrigo: parse command line, only needed without UI
  parseCmd();

  // TODO @rodrigo: print startup information, only needed without UI
  printStartupInfo();

  // TODO @rodrigo: read property file, only needed without UI
  //if(m_propertyFileInput.find(".toml") == std::basic_string<char>::npos) {
  //  // Context::readPropertyFile(, m_propertyFileInput);
  //} else {
  //  Context::readPropertyFile(TOML, m_propertyFileInput);
  //}

  // TODO @rodrigo: variable like scratch space
  //float scratchSize = Context::getBasicProperty<float>("scratchSize", AT_);
  //if(Context::propertyExists("testVariable")) {
  //  std::cout << "Property testVariables does exist!" << std::endl;
  //}

  // Create a new AXIS application, the class that controls the actual program
  mApplication = new Application();
}

// Environment destructor
Environment::~Environment() {
  if(mApplication != nullptr) delete mApplication;
}

// Run Environment
int Environment::run() {
  // Print to check for execution
  std::cout << "Running Environment run()..." << std::endl;

  //cadBlock = Context::getBasicProperty<bool>("cadBlock", AT_, &cadBlock);

  // Return if CAD application is not enabled
  //if(!cadBlock) {
  //  return 0;
  //}

  // TODO @rodrigo: maybe run with different template parameters if needed like dimension
  mApplication->run();

  return 0;
}

// Read options sent via the command call when the program is executed
void Environment::parseCmd() {
  std::cout << "WARNING: This function is not yet implemented!" << std::endl;
}

void Environment::printStartupInfo() {
  std::cout << "WARNING: This function is not yet implemented!" << std::endl;
}
