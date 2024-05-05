#include "AST.h"
#include "Nodes.h"
#include "Nodes.cpp"
#include "Stack.h"
#include "Stack.cpp"
#include <iostream>

#include <sstream>

bool isNumber(const std::string& s) {
    // try {
    //     std::stoi(str);
    //     return true;
    // } catch (const std::invalid_argument&) {
    //     return false;
    // }
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
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
            stack.push(new Number(std::stoi(token)));
        }
        else{
            throw std::runtime_error("Invalid token: " + token);
        }
        // stack.print();
        // std::cout<<'\n';
    }
    AST* retNode = stack.pop();
    if (!stack.isEmpty()) throw std::runtime_error("Too many operands.");
    return retNode;
}
