#ifndef LIST_H
#define LIST_H
#include <string>

// TODO...

struct Node {
public:
    std::string key;
    int value;
    Node* next;
    Node* last;

public:
    Node(const std::string& str, int num);
};

class List{
public:
    Node* head;
    Node* tail;

    List();
    ~List();
    Node* insert(const std::string str, int num = 0);
    Node* find(const std::string str) const;
    Node* find_add(const std::string str, int num = 0);
    void remove(Node* node);
};

#endif
