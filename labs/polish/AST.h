#ifndef AST_H
#define AST_H

#include <string>

// This is the abstract base class that represents an AST node.
// Implement the subclasses you need in Nodes.h and Nodes.cpp.
// Implement the parse function in AST.cpp.
// Do not edit this file.

class AST {
public:
  // Class function for parsing and tree creation:
  static AST* parse(const std::string& expression);

public:
  // Virtual destructor:
  virtual ~AST() {}

  // Member functions for output:
  virtual void print() const = 0;
  virtual std::string prefix()  const = 0;
  virtual std::string postfix() const = 0;
  virtual double      value()   const = 0;
};

#endif
