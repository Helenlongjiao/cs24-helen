#include "Nodes.h"

#include <sstream>
#include <string>

// This creates the number format the autograder expects:
std::string format(double number) {
  std::ostringstream stream;
  stream << number;
  return stream.str();
}

//Number implementation
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

//Operator implementation
Operator::Operator(std::string opr): opr(opr){}

std::string Operator::prefix() const{}
std::string Operator::postfix() const{}
double Operator::value() const{
  if(opr == "+"){}
  else if(opr == "-"){}
  //...
}