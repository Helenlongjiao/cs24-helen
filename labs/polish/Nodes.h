#ifndef NODES_H
#define NODES_H

#include "AST.h"

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.

class Number: public AST{
public:
    int data;
public:
    Number(int data);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class Operator: public AST{
public:
    std::string sign;
public:
    Operator(std::string sign);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class Negation: public AST{

    Negation();
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
#endif
