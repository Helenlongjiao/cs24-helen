#include "Tree.h"
#include <iostream>

int main(){
    Tree tree;
    tree.insert("d");
    tree.insert("b");
    tree.insert("e");
    tree.insert("a");
    tree.insert("c");
    tree.insert("f");
    tree.insert("f");
    std::cout<<tree.find("f");
    return 0;
}
