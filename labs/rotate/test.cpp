#include "Tree.h"
#include <iostream>

int main(){
    Tree tree;
    tree.insert("ddd");
    tree.insert("bbb");
    tree.insert("eee");
    tree.insert("aaa");
    tree.insert("ccc");
    tree.insert("fff");
    std::cout<<tree.find("ddd");
    return 0;
}
