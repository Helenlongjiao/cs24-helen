#ifndef TREE_H
#define TREE_H

#include "Node.h"
<<<<<<< HEAD
#include <string>
#include <iostream>

class Tree {
    Node* head;
    size_t cnt;
=======

class Tree {
  // Member Variables

  // Private Helper Functions
>>>>>>> ebb75c898422bcc08c5d6a7d691feda7bfaac208

public:
  Tree();
  ~Tree();
<<<<<<< HEAD
=======

  // Public Member Functions
>>>>>>> ebb75c898422bcc08c5d6a7d691feda7bfaac208
  void        clear();
  size_t      count() const;
  bool        contains(const std::string& s) const;
  size_t      find(const std::string& s) const;
<<<<<<< HEAD
  void promote(Node* start, Node* curr);
  void        insert(const std::string& s);
  Node* lookup_rec(Node* curr, size_t index) const;
  std::string lookup(size_t index) const;
  void        print() const;
  Node* insert_rec(Node* curr, const std::string input);
  Node* lookup_node(size_t index) const;
  void        remove(size_t index);
};

#endif
=======
  void        insert(const std::string& s);
  std::string lookup(size_t index) const;
  void        print() const;
  void        remove(size_t index);
};

#endif
>>>>>>> ebb75c898422bcc08c5d6a7d691feda7bfaac208
