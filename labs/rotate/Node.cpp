#include "Node.h"
#include <string>
#include <iostream>

Node::Node(){
    data = "\n";
    weight = 1;
    left = nullptr;
    right = nullptr;
}

Node::Node(std::string data, Node* left, Node* right){
    this->data = data;
    this->left = left;
    this->right = right;
    weight = 1;
}