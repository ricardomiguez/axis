#include "block.h"

#include <iostream>

// Block Constructor
Block::Block(const int blockId, const bool isActive) : m_blockId(blockId) {

  if(isActive) {
    // Determine certain ids and domains. IMPORTANT: Once necessary is MPI is ever used
    std::cout << "Not yet necessary..." << std::endl;
  }

    // Get output and test case directories
    std::basic_string<char> testDir = "./";
    m_testDir = " ";
    m_outputDir = " ";
    //m_testDir = Context::getSolverProperty<std::basic_string<char>>("testDir", AT_, &testDir);
    //m_outputDir = Context::getSolverProperty<std::basic_string<char>>("outputDir", AT_, &outputDir);
    m_outputDir = testDir + m_outputDir;
    m_testDir = testDir + m_testDir;
}
