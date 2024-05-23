#include "Heap.h"
#include <iostream>

// Use this file to test your Heap class!
// This file won't be graded - do whatever you want.

int main() {
    Heap heap(8);

    heap.push("a",4);
    heap.push("b",2);
    heap.push("c",3);

    for(size_t i = 0; i < heap.count(); ++i){
        std::cout<<heap.lookup(i).value<<"\n";
    }
    return 0;
}
