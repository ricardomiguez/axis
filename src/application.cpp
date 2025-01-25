#include "application.h"

#include <iostream>
// Here comes basically all the program classes head files
//#include ...

Application::Application() {

}

Application::~Application() {

}

void Application::run() {
  std::cout << "AXIS MAIN LOOP" << std::endl;

  // TODO @rodrigo: create a function to create timers

  // TODO @rodrigo: create output directories, if it doesn't exist yet

  // Create geometry (Can be created instead inside of the create application below) //

  // Create block
  //cadBlock();

  // Initialize the block
  //m_block->initBlock();

  // Finilize block
  //m_block->finilizeBlock();

  // Postprocessing if needed

  cleanUp();
}

void Application::cleanUp() {
  // Cleanup blocks
  //m_block->cleanUp();
}
