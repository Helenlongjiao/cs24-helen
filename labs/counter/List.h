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
    void insert(const std::string str, int num = 0);
    Node* find(const std::string str) const;
    void remove(const std::string str);
};

#endif
