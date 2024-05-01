#include "Tree.h"
#include <iostream>

int main(){
    Tree tree;

//test code for lookup/remove (duplicate data)
    // tree.insert("d");
    // tree.insert("b");
    // tree.insert("e");
    // tree.insert("a");
    // // tree.insert("c");
    // tree.insert("h");
    // tree.insert("g");
    // tree.insert("f");
    // tree.insert("h");
    // tree.remove(1);
    // tree.print();

    tree.insert("scape");
    std::cout<<tree.count()<<'\n';
    tree.print();
    tree.remove(0);
    std::cout<<tree.count()<<'\n';
    tree.print();

//test code for find duplicate
    // tree.insert("mushroom");
    // tree.insert("badger");
    // tree.insert("badger");
    // tree.insert("badger");
    // tree.insert("mushroom");
    // tree.insert("mushroom");
    // tree.insert("snake");
    // tree.insert("snake");
    // // tree.print();
    // std::cout<<tree.find("mushroom");

//test code for promotion
    // tree.insert("a");
    // tree.insert("b");
    // std::cout<<"insert c\n";
    // tree.insert("c");
    // tree.print();
    // return 0;
}
