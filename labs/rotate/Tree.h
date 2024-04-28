#ifndef TREE_H
#define TREE_H

#include "Node.h"
#include <string>
#include <iostream>

class Tree {
    Node* head;
    int cnt;

public:
  Tree();
  ~Tree();
  void        clear();
  size_t      count() const;
  bool        contains(const std::string& s) const;
  size_t      find(const std::string& s) const;
  void        insert(const std::string& s);
  std::string lookup(size_t index) const;
  void        print() const;
  void        remove(size_t index);
};

#endif