#ifndef APPLICATION_H
#define APPLICATION_H

#include <memory>
// TODO @rodrigo: implement a grid class later on the road
//class Grid;

class Geometry;
class Block;

class Application {
  public:
    Application();
    ~Application();

    void run();

  private:
    // Variables
    std::unique_ptr<Block> m_block;

    // Methods
    void readProperties();
    void cleanUp();

    void createBlock(const int blockId);
};

#endif
