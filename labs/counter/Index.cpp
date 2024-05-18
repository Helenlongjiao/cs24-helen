#include "Index.h"

// Index Member Functions

hashList::hashList(){
    tail = nullptr;
}

hashList::~hashList(){
    for(int i = 0; i < 10000; ++i){
        hashNode* curr = head[i];
        hashNode* curr_next;
        while(curr != nullptr){
            curr_next = curr->next;
            delete curr;
            curr = curr_next;
        }
        // delete head[i];
    }
}

int hashList::hashFunction(const std::string str) const{
    int ret = 0;
    for (char c : str) {
        ret += static_cast<int>(c);
    }
    return ret % 10000;
}

void hashList::insert(Node* node, const std::string str){
    int index = hashFunction(str);
    // for (char c : str) {
    //     index += static_cast<int>(c);
    // }
    hashNode* newNode = new hashNode;
    newNode->key = str;
    newNode->index = index;
    newNode->next = nullptr;
    newNode->node = node;
    if(head[index] == nullptr){
        head[index] = newNode;
    }
    if(tail != nullptr){
        tail->next = newNode;
    }
    tail = newNode;
}

Node* hashList::find(const std::string str) const{
    int index = hashFunction(str);
    while(true){
        hashNode* curr = head[index];
        if(curr == nullptr){
            return nullptr;
        }
        if(curr->key == str){
            return curr->node;
        }
        curr = curr->next;
    }
    return nullptr;
}