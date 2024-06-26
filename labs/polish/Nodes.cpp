#include "Nodes.h"

#include <cmath>
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
Number::Number(double data){
  this->data = data;
}

Number::~Number(){}

std::string Number::prefix() const{
  return format(data);
}
std::string Number::postfix() const{
  return format(data);
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

Operator::~Operator(){
  delete left;
  delete right;
}

std::string Operator::prefix() const{
  std::string output;
  output += opr;
  output += ' ';
  output.append(left->prefix());
  output += ' ';
  output.append(right->prefix());
  return output;
}

std::string Operator::postfix() const{
  std::string output;
  output.append(left->postfix());
  output += ' ';
  output.append(right->postfix());
  output += ' ';
  output += opr;
  return output;
}

double Operator::value() const{
  if(opr == '+'){
    long double templ;
    long double tempr;
    templ = left->value();
    tempr = right->value();
    return templ + tempr;
  }
  else if(opr == '-'){
    return left->value() - right->value();
  }
  else if(opr == '*'){
    long double templ;
    long double tempr;
    templ = left->value();
    tempr = right->value();
    return templ * tempr;
  }
  else if(opr == '/'){
    long double templ;
    long double tempr;
    templ = left->value();
    tempr = right->value();
    if(right->value() == 0){
      throw std::runtime_error ("Division by zero.");
    }
    return templ / tempr;
  }
  else if(opr == '%'){
    long double templ;
    long double tempr;
    templ = left->value();
    tempr = right->value();
    if(right->value() == 0){
      throw std::runtime_error ("Division by zero.");
    }
    // return templ - (static_cast<int>(templ / tempr) * tempr);
    return std::fmod(templ, tempr);
  }
  return 0;
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

Negation::~Negation(){
  delete child;
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
  output += " ~";
  return output;
}

double Negation::value() const{
  return (0 - child->value());
}

// void Negation::print() const{
//   std::cout<<'~';
//   child->print();
// }