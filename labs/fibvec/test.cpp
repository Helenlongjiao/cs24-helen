#include "FibVec.h"
#include <iostream>

// Use this file to test your FibVec class!
// This file won't be graded - do whatever you want.


int main() {
  FibVec fibvec;
  fibvec.push(1);
  fibvec.push(2);
  fibvec.push(3);
  fibvec.push(4);
  fibvec.push(5);
  fibvec.remove(2);
  for(int i = 0; i < fibvec.count(); ++i){
    std::cout<<fibvec.lookup(i);
  }
  

  return 0;
}
