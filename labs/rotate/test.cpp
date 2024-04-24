#include "Tree.h"
#include <iostream>

int main(){
    Tree tree;
    tree.insert("a");
    tree.insert("b");
    tree.insert("c");
    tree.insert("d");
    tree.insert("f");
    tree.insert("e");
    tree.print();
    return 0;
}
