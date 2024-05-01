#include "Tree.h"
#include <iostream>

int main(){
    Tree tree;

//test code for lookup/remove (duplicate data)
    // tree.insert("d");
    // tree.insert("b");
    // tree.insert("e");
    // tree.insert("a");
    // tree.insert("c");
    // tree.insert("h");
    // tree.insert("g");
    // tree.insert("f");
    // tree.insert("h");
    // tree.print();
    // std::cout<<tree.contains("f");
    tree.insert("d");
    tree.remove(0);
    tree.print();


//test code for find duplicate
    // tree.insert("badger");
    // tree.insert("badger");
    // tree.insert("badger");
    // tree.insert("mushroom");
    // tree.insert("mushroom");
    // tree.insert("mushroom");
    // tree.insert("snake");
    // tree.insert("snake");
    // std::cout<<tree.find("snake");

//test code for promotion
    // tree.insert("a");
    // tree.insert("b");
    // std::cout<<"insert c\n";
    // tree.insert("c");
    // tree.print();
    // return 0;
}
