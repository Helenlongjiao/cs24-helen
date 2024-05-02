#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <string>
#include <iostream>

class Tree {
    Node* head;
    size_t cnt;

public:
  Tree();
  ~Tree();
  void        clear();
  size_t      count() const;
  bool        contains(const std::string& s) const;
  size_t      find(const std::string& s) const;
  void promote(Node* start, Node* curr, std::string target);
  void        insert(const std::string& s);
  Node* lookup_rec(Node* curr, size_t index) const;
  std::string lookup(size_t index) const;
  void        print() const;
  Node* insert_rec(Node* curr, const std::string input);
  Node* lookup_node(size_t index) const;
  void        remove(size_t index);
};

#endif