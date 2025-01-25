#include "ioget.h"

#include "iotoml.h"

IOToml* IOGet::m_IOToml;
std::basic_string<char> IOGet::m_name;

void IOGet::readPropertyFile() {

}

int IOGet::getBasicPropertyOverloaded(const std::basic_string<char>& name, bool has_default,
                                      const int* default_value, int pos) {
  int propertyValue;
  propertyValue = getBasicPropertyImplict(name, has_default, default_value, pos,
                                          [](int* i, int p) { return (*(i)->asInt(p)); });

  return propertyValue;
}

float IOGet::getBasicPropertyOverloaded(const std::basic_string<char>& name, bool has_default,
                                      const float* default_value, int pos) {

  float propertyValue;
  propertyValue = getBasicPropertyImplict(name, has_default, default_value, pos,
                                          [](float* i, int p) { return (*(i)->asFloat(p)); });

  return propertyValue;
}

std::basic_string<char> IOGet::getBasicPropertyOverloaded(const std::basic_string<char>& name, bool has_default,
                                      const std::basic_string<char>* default_value, int pos) {

  std::basic_string<char> propertyValue;
  propertyValue = getBasicPropertyImplict(name, has_default, default_value, pos,
                                          [](std::basic_string<char>* i, int p) { return (*(i)->asString(p)); });

  return propertyValue;
}

bool IOGet::getBasicPropertyOverloaded(const std::basic_string<char>& name, bool has_default,
                                      const bool* default_value, int pos) {

  bool propertyValue;
  propertyValue = getBasicPropertyImplict(name, has_default, default_value, pos,
                                          [](bool* i, int p) { return (*(i)->asString(p)); });

  return propertyValue;
}

// TODO @rodrigo: This seems to be too complex for a simple file read
//template <typename T>
//T IOGet::getBasicPropertyImplicit(const std::basic_string<char>& name, bool has_default,
//                                  const T* defaultValue, int position) {
//  if(propertyExists(name)) {
//  }
//}
