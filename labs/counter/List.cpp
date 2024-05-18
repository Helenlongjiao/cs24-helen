#include "List.h"
#include <iostream>

// List Member Functions

Node::Node(const std::string& str, int num){
    key = str;
    value = num;
    last = nullptr;
    next = nullptr;
}

List::List(){
    head = nullptr;
    tail = nullptr;
}

List::~List(){
    Node* curr = head;
    while(curr != nullptr){
        Node* curr_next = curr->next;
        delete curr;
        curr = curr_next;
    }
}

Node* List::insert(const std::string str, int num){
    Node* node = new Node(str, num);
    node->next = nullptr;
    if(head == nullptr){
        head = node;
    }
    else{
        node->last = tail;
        tail->next = node;
    }
    tail = node;
    return node;
}

Node* List::find(const std::string str) const{
    Node* curr = head;
    while(curr != nullptr){
        if(curr->key == str){
            // std::cout << "found";
            return curr;
        }
        // std::cout << "not found" << curr->key;
        curr = curr->next;
    }
    return nullptr;
}

Node* List::find_add(const std::string str, int num) {
    Node* node = find(str);
    if(node != nullptr) {
        return node;
    }
    insert(str, num);
    return tail;
}

void List::remove(Node* node){
    if(node->last != nullptr){
        node->last->next = node->next;
    }
    else{
        head = node->next;
    }
    if(node->next != nullptr){
        node->next->last = node->last;
    }
    else{
        tail = node->last;
    }
    delete node;
    
}