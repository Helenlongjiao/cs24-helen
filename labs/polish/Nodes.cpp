#include "Nodes.h"

#include <sstream>
#include <string>

// This creates the number format the autograder expects:
std::string format(double number) {
  std::ostringstream stream;
  stream << number;
  return stream.str();
}


Number::Number(int data): data(data){}

std::string Number::prefix() const{
  return std::to_string(data);
}
std::string Number::postfix() const{
  return std::to_string(data);
}
double Number::value() const{
  return data;
}