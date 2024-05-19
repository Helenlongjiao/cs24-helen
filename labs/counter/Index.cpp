#include "Index.h"

// Index Member Functions

hashList::hashList(){
    for(int i = 0; i < 10000; ++i){
        head[i] = nullptr;
    }
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
    }
    delete[] head;
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
        newNode->last = nullptr;
        head[index] = newNode;
    }
    else{
        hashNode* tail = head[index];
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = newNode;
        newNode->last = tail;
    }
}

Node* hashList::find(const std::string str) const{
    int index = hashFunction(str);
    hashNode* curr = head[index];
    while(true){
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

void hashList::remove(Node* node){
    int index = hashFunction(node->key);
    hashNode* curr = head[index];
    while(true){
        if(curr == nullptr){
            return;
        }
        if(curr->key == node->key){
            if(curr->next != nullptr){
                if(curr->last != nullptr){
                    curr->next->last = curr->last;
                    curr->last->next = curr->next;
                }
                else{
                    head[index] = curr->next;
                    curr->next->last = nullptr;
                }
            }
            else{
                if(curr->last != nullptr){
                    curr->last->next = nullptr;
                }
                else{
                    head[index] = nullptr;
                }
            }
            delete curr;
            return;
        }
        curr = curr->next;
    }
}