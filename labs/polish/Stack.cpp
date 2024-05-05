#include "Stack.h"


// Implement your Stack member functions here.

Stack::Stack(){
    index = -1;
} // Constructor
void Stack::push(AST* element){
    if(index == 2){
        throw std::runtime_error("Too many operands.");
    }
    stackArray[++index] = element;
} // Pushes an element onto the stack
AST* Stack::pop(){
    if(index == -1){
        throw std::runtime_error("Not enough operands.");
    }
    return stackArray[index];
} // Pops the top element from the stack
bool Stack::isEmpty(){
    if(index == -1){
        return true;
    }
    else{
        return false;
    }
} // Checks if the stack is empty