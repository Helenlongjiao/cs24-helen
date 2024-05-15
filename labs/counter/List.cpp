#include "List.h"

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
    }
    tail = node;
}

Node* List::find(const std::string str) const{
    Node* curr = head;
    while(curr != nullptr){
        if(curr->key == str){
            return curr;
        }
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
            curr->last->next = curr->next;
            curr->next->last = curr->last;
            delete curr;
            break;
        }
        curr = curr->next;
    }
}