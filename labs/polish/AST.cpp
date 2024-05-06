#include "AST.h"
#include "Nodes.h"
#include "Stack.h"
#include <iostream>

#include <sstream>

bool isNumber(const std::string& str) {
    std::istringstream iss(str);
    double num;
    iss >> std::noskipws >> num; // Read the number, skipping white spaces
    return iss.eof() && !iss.fail(); // Check if reached end of stream and no errors
}


AST* AST::parse(const std::string& expression) {
    Stack stack;
    std::string token;
    std::istringstream stream(expression);

    while(stream >> token) {
        if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%"){
            AST* right = stack.pop();
            AST* left = stack.pop();
            stack.push(new Operator(token.c_str()[0], left, right));
        }
        else if(token == "~"){
            AST* child = stack.pop();
            stack.push(new Negation(child));
        }
        else if(isNumber(token)){
            double value;
            value = std::stod(token);
            stack.push(new Number(value));
        }
        else{
            stack.clean();
            throw std::runtime_error("Invalid token: " + token);
        }
        // stack.print();
        // std::cout<<'\n';
    }
    if(stack.isEmpty()) {
        stack.clean();
        throw std::runtime_error("No input.");
    }
    AST* retNode = stack.pop();
    if (!stack.isEmpty()) {
        stack.clean();
        throw std::runtime_error("Too many operands.");
    }
    return retNode;
}
