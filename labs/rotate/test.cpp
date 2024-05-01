#include "Tree.h"
#include <iostream>

int main(){
    Tree tree;

//test code for lookup/remove (duplicate data)
    tree.insert("d");
    tree.insert("b");
    tree.insert("e");
    tree.insert("a");
    tree.insert("c");
    // tree.insert("h");
    // tree.insert("g");
    // tree.insert("f");
    // tree.insert("h");
    tree.print();
    tree.remove(1);
    tree.print();



    // tree.insert("d");
    // tree.insert("b");
    // tree.insert("e");
    // tree.insert("a");
    // tree.insert("c");
    // tree.insert("h");
    // tree.insert("f");
    // tree.insert("j");

//test code for promotion
    // tree.insert("a");
    // tree.insert("b");
    // std::cout<<"insert c\n";
    // tree.insert("c");
    // tree.print();
    // return 0;
}
