#include <iostream>
#include <string>
#include "Tree.h"
#include "Node.h"
 
Tree::Tree(){
    head = nullptr;
    cnt = 0;
}

Tree::~Tree(){
    clear();
}

void rec_clear(Node* curr){
    // if(curr->left != nullptr){
    //     rec_clear(curr->left);
    //     delete curr->left;
    //     if(curr->right->right != nullptr || curr->right->left != nullptr){
    //         rec_clear(curr->right);
    //     }
    //     delete curr->right;
    // }
    // else{
    //     delete curr->right;
    // }

    if (curr == nullptr) {
        return;
    }

    if (curr->left != nullptr) {
        rec_clear(curr->left);
        delete curr->left;
        curr->left = nullptr;
    }

    if (curr->right != nullptr) {
        rec_clear(curr->right);
        delete curr->right;
        curr->right = nullptr;
    }
}

void Tree::clear(){
    rec_clear(head);
    delete head;
    head = nullptr;
}

size_t Tree::Tree::count() const{
    return cnt;
}

bool contains_rec(Node* curr, std::string input){
    if((input > curr->data) && (curr -> right != nullptr)){
        return contains_rec(curr->right, input);
    }
    else if((input < curr->data) && (curr ->left != nullptr)){
        return contains_rec(curr->left, input);
    }
    else if(((input > curr->data) && (curr -> right == nullptr))
            ||
            ((input < curr->data) && (curr -> left == nullptr))){
        return false;
    }
    else{
        return true;
    }
}

bool Tree::contains(const std::string& s) const{
    return contains_rec(head, s);
}

size_t Tree::find(const std::string& s) const{
    return 1;
}

Node* insert_rec(Node* curr, const std::string input) {
    if (input > curr->data) {
        if (curr->right != nullptr) {
            return insert_rec(curr->right, input);
        } else {
            curr->weight ++;
            Node* newOne = new Node();
            newOne->data = input;
            (*curr).right = newOne;
            return newOne;
        }
    } else{
        if (curr->left != nullptr) {
            return insert_rec(curr->left, input);
        } else {
            curr->weight ++;
            Node* newOne = new Node();
            newOne->data = input;
            (*curr).left = newOne;
            return newOne;
        }
    }
}

void Tree::insert(const std::string& s){
    if(head == nullptr){
        Node* newOne = new Node();
        newOne->data = s;
        head = newOne;
        cnt ++;
    } else {
        insert_rec(head, s);
        cnt++;
    }
}


std::string Tree::lookup(size_t index) const{
    return "0";
}

std::string print_rec(Node* curr) {
    if (curr == nullptr) {
        return "-";
    } else if (curr->left == nullptr && curr->right == nullptr) {
        return curr->data;
    }else{
        std::string leftStr = print_rec(curr->left);
        std::string rightStr = print_rec(curr->right);
        return "(" + leftStr + " " + curr->data + " " + rightStr + ")";
    }
}

void Tree::print() const{
    std::cout << print_rec(head) << '\n';
}

void Tree::remove(size_t index){}
void Tree::promote(Node& node){}

// int index(Node* curr, Node* node, int n){
//     if(curr->left != nullptr){
//         return index(curr->left, node, n);
//     }
//     else if(curr->data == node->data){
//         return n;
//     }
//     else{
//         return index()
//     }
// }