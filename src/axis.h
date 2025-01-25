#ifndef AXIS_H
#define AXIS_H

class AXIS {
  public:
    AXIS(int argc, char** argv) : m_argc(argc), m_argv(argv) {}

    int run();

  private:
    int m_argc = 0;
    char** m_argv = nullptr;
};

#endif
