#ifndef FIBVEC_H
#define FIBVEC_H

// This provides the size_t type:
#include <cstddef>

class FibVec {
  // Member Variables
  int* value;
  size_t capa;
  size_t cnt;
  size_t fibn;

  // Helper Functions

public:
  // Constructor and Destructor
  FibVec();
  ~FibVec();

  // Member Functions
  size_t capacity() const;
  size_t count() const;
  void insert(int n, size_t index);
  int lookup(size_t index);
  int pop();
  void push(int n);
  int remove(size_t index);
  //helper function
  void resize_add();
  void resize_min();
};

#endif
