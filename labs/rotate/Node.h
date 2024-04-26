#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>

struct Node{
    std::string data;
    Node* left;
    Node* right;
    size_t weight;

    Node();
    Node(std::string data, Node* left, Node* right);
};
#endif