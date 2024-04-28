#include "Tree.h"
#include <iostream>

int main(){
    Tree tree;
    tree.insert("d");
    tree.insert("b");
    tree.insert("e");
    tree.insert("a");
    tree.insert("c");
    tree.insert("h");
    tree.insert("g");
    tree.insert("f");
    tree.insert("h");

    // tree.insert("d");
    // tree.insert("b");
    // tree.insert("e");
    // tree.insert("a");
    // tree.insert("c");
    // tree.insert("h");
    // tree.insert("f");
    // tree.insert("j");

    // tree.insert("a");
    // tree.insert("b");
    // tree.insert("c");
    
    std::cout<<tree.find("h");
    return 0;
}
