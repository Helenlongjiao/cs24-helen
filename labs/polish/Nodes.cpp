#include "Nodes.h"

#include <sstream>
#include <string>

// This creates the number format the autograder expects:
std::string format(double number) {
  std::ostringstream stream;
  stream << number;
  return stream.str();
}


class Negation: public AST{
public:
    int data;
public:
    Negation(int data): data(data) {}
};
