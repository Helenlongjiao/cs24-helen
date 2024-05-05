#include "Nodes.h"

#include <sstream>
#include <string>
#include <iostream>

// This creates the number format the autograder expects:
std::string format(double number) {  //这个在哪里用到？
  std::ostringstream stream;
  stream << number;
  return stream.str();
}

//Number implementation
Number::Number(int data){
  this->data = data;
}

std::string Number::prefix() const{
  return std::to_string(data) + ' ';
}
std::string Number::postfix() const{
  return std::to_string(data) + ' ';
}
double Number::value() const{
  return data;
}
// void Number::print() const{
//   std::cout<<data;
// }

//Operator implementation
Operator::Operator(char opr, AST* left, AST* right){
  this->opr = opr;
  this->left = left;
  this->right = right;
}

std::string Operator::prefix() const{
  std::string output;
  output += opr;
  output += ' ';
  output.append(left->prefix());
  output.append(right->prefix());
  return output;
}

std::string Operator::postfix() const{
  std::string output;
  output.append(left->postfix());
  output.append(right->postfix());
  output += opr;
  output += ' ';
  return output;
}

double Operator::value() const{
  if(opr == '+'){}
  else if(opr == '-'){}
  return 0;
  //...
}

// void Operator::print() const{
//   std::cout<< opr <<" (left child: ";
//   left->print();
//   std::cout<< " right child: ";
//   right->print();
//   std::cout<<") ";
// }

//Negation implementation
Negation::Negation(AST* child){
  this->child = child;
}

std::string Negation::prefix() const{
  std::string output;
  output += "~ ";
  output.append(child->prefix());
  return output;
}

std::string Negation::postfix() const{
  std::string output;
  output.append(child->postfix());
  output += "~ ";
  return output;
}

double Negation::value() const{
  return 0;
}

// void Negation::print() const{
//   std::cout<<'~';
//   child->print();
// }