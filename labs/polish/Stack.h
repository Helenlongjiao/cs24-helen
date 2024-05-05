#ifndef STACK_H
#define STACK_H

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.

#include "AST.h"
class Stack {
private:
    static const int MAX_SIZE = 100; // Maximum size of the stack
    AST* stackArray[MAX_SIZE];
    int index; // Index of the top element

public:
    Stack(); // Constructor
    void push(AST* element); // Pushes an element onto the stack
    AST* pop(); // Pops the top element from the stack
    bool isEmpty(); // Checks if the stack is empty
};

#endif
