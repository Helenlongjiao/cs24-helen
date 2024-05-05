#include "Node.h"
<<<<<<< HEAD
#include <string>
#include <iostream>

Node::Node(){
    data = "\n";
    weight = 1;
    left = nullptr;
    right = nullptr;
    parent = nullptr;
}

Node::Node(std::string data, Node* left, Node* right){
    this->data = data;
    this->left = left;
    this->right = right;
    parent = nullptr;
    weight = 1;
}

Node::Node(const Node& other){
    this->left = other.left;
    this->right = other.right;
    weight = other.weight;
    parent = other.parent;
    data = other.data;
}
=======

// Node Function Implementations
>>>>>>> ebb75c898422bcc08c5d6a7d691feda7bfaac208
