#ifndef NODES_H
#define NODES_H

#include "AST.h"

// Declare your AST subclasses here.
// Implement their member functions in Nodes.cpp.

class Number: public AST{
public:
    double data;
public:
    ~Number();
    void print() const;
    Number(double data);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class Operator: public AST{
public:
    char opr;
    AST* left;
    AST* right;
public:
    // void print() const;
    ~Operator();
    Operator(char opr, AST* left, AST* right);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class Negation: public AST{
public:
    AST* child;
public:
    void print() const;
    ~Negation();
    Negation(AST* child);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};
#endif
