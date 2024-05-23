#include "WordList.h"
#include <iostream>

bool isLowerCase(const std::string& str) {
    for (char c : str) {
        if (!std::islower(c)) {
            return false;
        }
    }
    return true;
}

WordList::WordList(std::istream& stream){
    std::string line;
    while (std::getline(stream, line)) {
        mWords.push_back(line);
    }
}

Heap WordList::correct(const std::vector<Point>& points, size_t maxcount, float cutoff) const{
    Heap heap(maxcount);
    for(std::string word : mWords){
        if(word.size() == points.size() && isLowerCase(word)){
            float total_score = 0;
            for (size_t i = 0; i < word.size(); ++i) {
                Point keyLoc = QWERTY[word[i] - 'a'];
                float dx = points[i].x - keyLoc.x;
                float dy = points[i].y - keyLoc.y;
                float dist = std::sqrt(dx * dx + dy * dy);
                float score = 1 / (10 * dist * dist + 1);
                total_score += score;
            }
            total_score = total_score / word.size();

            if (total_score >= cutoff) {
                if (heap.count() < maxcount) {
                    heap.push(word, total_score);
                } else if (total_score > heap.top().score) {
                    heap.pushpop(word, total_score);
                }
            }
        }
    }
    return heap;
}