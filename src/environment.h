#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <string>

class Application;

// Environment class
class Environment {
  public:
    Environment(int, char**);
    ~Environment();

    int run();
    int end();
    static int m_argc;
    static char** m_argv;

  private:
    Application* mApplication;
    static void parseCmd();
    static void printStartupInfo();

    std::basic_string<char> m_inputFile = "input.toml";
};

#endif
