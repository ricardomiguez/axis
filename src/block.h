#ifndef BLOCK_H
#define BLOCK_H

#include <string>

class Application;

// Parent class that is the base for all blocks
class Block {
  // Declared as a friend for function which should only be used in Application
  friend Application;

  private:
    // Path to a test case directory
    std::basic_string<char> m_testDir;

    // Path to the output directory
    std::basic_string<char> m_outputDir;

    // Protected doesn't allow instance of non-derived classes
  protected:
    Block(const int blockId, const bool isActive = true);

    // Unique block identifier
    const int m_blockId;

  public:
    virtual ~Block() = default;

    virtual void initBlock() = 0;
    virtual void finalizeBlock() = 0;
    virtual void cleanUp() = 0;

    std::basic_string<char> testDir() const { return m_testDir; }
    std::basic_string<char> outputDir() const { return m_outputDir; }
};

#endif
