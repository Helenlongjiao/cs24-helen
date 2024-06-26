#include "Counter.h"

const std::string& Counter::Iterator::key() const{
    return curr->key;
}

// Counter::Iterator Member Functions
int Counter::Iterator::value() const{
    return curr->value;
}

void Counter::Iterator::operator ++ (){
    if(curr != nullptr){
        curr = curr->next;
    }
}

bool Counter::Iterator::operator == (const Iterator& other) const{
    return curr == other.curr;
}

bool Counter::Iterator::operator != (const Iterator& other) const{
    return curr != other.curr;
}