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

List::~List(){}

void List::insert(const std::string str, int num){
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

void List::remove(const std::string str){
    Node* curr = head;
    while(curr != nullptr){
        if(curr->key == str){
            if(curr->last != nullptr){
                curr->last->next = curr->next;
            }
            else{
                head = curr->next;
            }
            if(curr->next != nullptr){
                curr->next->last = curr->last;
            }
            else{
                tail = curr->last;
            }
            delete curr;
            break;
        }
        curr = curr->next;
    }
}