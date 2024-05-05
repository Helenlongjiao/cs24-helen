#include "AST.h"
#include "Nodes.h"

#include <sstream>

bool isNumber(const std::string& str) {
    try {
        std::stoi(str);
        return true;
    } catch (const std::invalid_argument&) {
        return false;
    }
}

AST* AST::parse(const std::string& expression) {
    std::string token;
    std::istringstream stream(expression);

    while(stream >> token) {
        if(token == "+" || token == "-" || token == "*" || token == "/" || token == "%"){
            AST* right = stack.pop();
            AST* left = stack.pop();
            stack.push(new Operator(token, left, right));
        }
        else if(token == "~"){
            AST* child = stack.pop();
            stack.push(new Negation(token, child));
        }
        else if(isNumber){
            stack.push(new Number(token));
        }
        else{
            throw std::runtime_error("Invalid token: " + token);
        }
    }

    // ...
}
