#ifndef STACK_H
#define STACK_H

// Use this file to define your Stack type.
// Implement its member functions in Stack.cpp.

#include "AST.h"
class Stack {
private:
    AST* stackArray[150];
    int index; // Index of the top element

public:
    Stack(); // Constructor
    // void print();
    ~Stack();
    void clean();
    void push(AST* element); // Pushes an element onto the stack
    AST* pop(int n); // Pops the top element from the stack
    bool isEmpty(); // Checks if the stack is empty
};


#endif
