#include "WordList.h"
#include <iostream>

WordList::WordList(std::istream& stream){
    std::string line;
    while (std::getline(stream, line)) {
        mWords.push_back(line);
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    
}