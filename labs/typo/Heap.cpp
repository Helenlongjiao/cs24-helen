#include "Heap.h"
#include <iostream>

Heap::Heap(size_t capacity){
    mData = new Entry[capacity];
    mCapacity = capacity;
    mCount = 0;
}

Heap::Heap(const Heap& other){
    for(size_t i = 0; i < mCount; ++i){
        mData[i] = other.mData[i];
    }
    mCapacity = other.mCapacity;
    mCount = other.mCount;
}

Heap::~Heap(){
    delete [] mData;
}

size_t Heap::capacity() const{
    return mCapacity;
}

size_t Heap::count() const{
    return mCount;
}

const Heap::Entry& Heap::lookup(size_t index) const{
    if (index >= mCount) {
        throw std::out_of_range("Index out of range");
    }
    return mData[index];
}


Heap::Entry Heap::pop(){
    if (mCount == 0) {
        throw std::underflow_error("Heap is empty");
    }
    Entry min = mData[0];
    mData[0] = mData[mCount];
    mCount --;

    size_t index = 0;
    while (index < mCount) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t smallest = index;

        if (left < mCount && mData[left].score < mData[smallest].score) {
            smallest = left;
        }
        if (right < mCount && mData[right].score < mData[smallest].score) {
            smallest = right;
        }
        if (smallest != index) {
            std::swap(mData[index], mData[smallest]);
            index = smallest;
        } else {
            break;
        }
    }

    return min;
}

Heap::Entry Heap::pushpop(const std::string& value, float score){
    if (mCount == 0) {
        throw std::underflow_error("Heap is empty");
    }
    Entry min = mData[0];
    mData[0].score = score;
    mData[0].value = value;

    size_t index = 0;
    while (index < mCount) {
        size_t left = 2 * index + 1;
        size_t right = 2 * index + 2;
        size_t smallest = index;

        if (left < mCount && mData[left].score < mData[smallest].score) {
            smallest = left;
        }
        if (right < mCount && mData[right].score < mData[smallest].score) {
            smallest = right;
        }
        if (smallest != index) {
            std::swap(mData[index], mData[smallest]);
            index = smallest;
        } else {
            break;
        }
    }

    return min;
}

void Heap::push(const std::string& value, float score){
    if(mCount == mCapacity){
        throw std::overflow_error("healp is full");
    }
    mData[mCount].score = score;
    mData[mCount].value = value;

    size_t index = mCount;
    while(mCount > 0){
        size_t index_par = (mCount - 1) / 2;
        if(mData[mCount].score < mData[index_par].score){
            std::swap(mData[index_par], mData[index]);
        }
        else{
            break;
        }
        index = index_par;
    }
    mCount ++;
}

const Heap::Entry& Heap::top() const{
    if (mCount == 0) {
        throw std::underflow_error("Heap is empty");
    }
    return mData[0];
}