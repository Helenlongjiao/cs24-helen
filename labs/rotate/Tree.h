#ifndef TREE_H
#define TREE_H

#include <string>
#include <iostream>
#include "Node.h"

struct Tree{
    Node* head;
    int cnt;

    Tree();
    ~Tree();
    void clear();
    int count() const;
    bool contains(std::string input) const;
    int find(std::string input) const;
    void insert(const std::string input);
    char lookup(int index) const;
    void print() const;
    void remove(int index);
    void promote(Node& node);
};
#endif