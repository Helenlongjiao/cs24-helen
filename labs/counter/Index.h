#ifndef INDEX_H
#define INDEX_H
#include "List.h"

class hashNode{
public:
    hashNode* next;
    std::string key;
    int index;
    Node* node;
};

class hashList{
private:
    hashNode** head = new hashNode*[10000];
    hashNode* tail;

public:
    hashList();
    ~hashList();
    void insert(Node* node, const std::string str);
    Node* find(const std::string str) const;
    int hashFunction(const std::string str) const;
};

#endif
