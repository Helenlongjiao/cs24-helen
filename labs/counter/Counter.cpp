#include "Counter.h"
#include "List.h"

// Counter Member Functions

Counter::Counter(){}
Counter::~Counter(){}

size_t Counter::count() const{
    return 1;
}
int Counter::total() const{
    return 1;
}

void Counter::inc(const std::string& key, int by){
    list.find(key)->value += by;
}

void Counter::dec(const std::string& key, int by){
    list.find(key)->value -= by;
}

void Counter::del(const std::string& key){}

int  Counter::get(const std::string& key) const{
    if(list.find(key) == nullptr){
        return 0;
    }
    else{
        return list.find(key)->value;
    }
}
void Counter::set(const std::string& key, int count){
    list.find(key)->value = count;
}

//The default constructor creates an empty Counter.

// The destructor cleans up any allocated memory.
// begin() returns an iterator to the first-inserted item in the counter.
// count() returns the number of keys stored in the counter.
// dec(k, d) decrements a count by a given value (default one).
// del(k) removes a key from the counter, setting its count to (implicit) zero.
// end() returns an invalid "end" iterator (see below).
// get(k) looks up a count by key. If the key isn't present, it returns zero.
// inc(k, d) increments a count by a given value (default one).
// set(k, v) sets a count by key.
// total() returns the sum of all counts in the counter.