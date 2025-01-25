#ifndef IOGET_H
#define IOGET_H

// Defines IOGet class used for reading properties

#include <list>
#include <string>

// For the time being toml will be the only type of input file
class IOToml;

class IOGet {
  public:
    static void readPropertyFile(const std::basic_string<char>& fileName);

    static bool propertyExists(const std::basic_string<char>& name);

    static void clear();

    static void init();

  private:
    static IOToml* m_IOToml;
    static std::basic_string<char> m_name;

  // Get properties
  public:
    template <typename T>
    static T getBasicProperty(const std::basic_string<char> name, int pos = 0) {
      T* defaultValue = nullptr;
      return getBasicPropertyOverloaded(name, false, defaultValue, pos);
    }

  private:
    static int getBasicPropertyOverloaded(const std::basic_string<char>& name, bool has_default,
                                            const int* default_value, int pos);
    static float getBasicPropertyOverloaded(const std::basic_string<char>& name, bool has_default,
                                            const float* default_value, int pos);
    static std::basic_string<char> getBasicPropertyOverloaded(const std::basic_string<char>& name, bool has_default,
                                            const std::basic_string<char>* default_value, int pos);
    static bool getBasicPropertyOverloaded(const std::basic_string<char>& name, bool has_default,
                                           const bool* default_value, int pos);

};

#endif
