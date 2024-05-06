#include "Stack.h"
#include <iostream>


// Implement your Stack member functions here.

Stack::Stack(){
    index = -1;
} // Constructor

// void Stack::print(){
//     for(int i = 0; i <= index; ++i){
//         stackArray[i]->print();
//     }
// }


Stack::~Stack(){
    clean();
}

void Stack::clean(){
    for(int i = 0; i <= index; ++i){
        delete stackArray[i];
    }
}

void Stack::push(AST* element){
    if(index == 4){
        clean();
        throw std::runtime_error("Too many operands.");
    }
    stackArray[++index] = element;
} // Pushes an element onto the stack
AST* Stack::pop(int n){
    if(index == -1){
        throw std::runtime_error("Not enough operands.");
    }
    if(n == 2 && index < 1){
        clean();
        throw std::runtime_error("Not enough operands.");
    }
    AST* temp = stackArray[index];
    index --;
    return temp;
} // Pops the top element from the stack


bool Stack::isEmpty(){
    if(index == -1){
        return true;
    }
    else{
        return false;
    }
} // Checks if the stack is empty