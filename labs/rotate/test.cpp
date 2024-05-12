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

    // tree.insert("alpha");
    // tree.insert("beta");
    // tree.insert("chi");
    // tree.insert("delta");
    // tree.insert("epsilon");
    // tree.insert("eta");
    // tree.insert("gamma");
    // tree.insert("iota");
    // tree.insert("kappa");
    // tree.insert("lambda");
    // tree.insert("nu");
    // tree.insert("omega");
    // tree.insert("omicron");
    // tree.insert("phi");
    // tree.insert("pi");
    // tree.insert("psi");
    // tree.insert("rho");
    // tree.insert("sigma");
    // tree.insert("tau");
    // tree.insert("theta");
    // tree.insert("upsilon");
    // tree.insert("xi");
    // tree.insert("zeta");

    tree.insert("Mercury");
    tree.insert("Earth");
    tree.insert("Mars");
    tree.insert("Jupiter");
    tree.insert("Saturn");
    tree.insert("Neptune");
    tree.insert("Venus");
    tree.insert("Uranus");


    // tree.insert("h");
    // tree.insert("a");
    // tree.insert("b");
    // tree.insert("c");
    // tree.insert("d");

    // tree.insert("Apollo");
    // tree.insert("Artemis");
    // tree.insert("Athena");
    // tree.insert("Dionysus");
    // tree.insert("Hades");
    // tree.insert("Hephaestus");
    // tree.insert("Hera");
    // tree.insert("Hermes");
    // tree.insert("Hestia");
    // tree.insert("Poseidon");
    // tree.insert("Zeus");
    tree.print();
    // std::cout<<tree.find("psi");
    tree.remove(3);
    std::cout<<tree.count();
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
    // tree.insert("sulfur");
    // tree.insert("tellurium");
    // tree.insert("polonium");
    // tree.insert("selenium");
    // tree.insert("oxygen");
    // tree.insert("livermorium");
    // tree.print();
    return 0;
}
