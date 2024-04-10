#include "FibVec.h"
#include<iostream>

// This provides exception types:
#include <stdexcept>

//helper function:fib
size_t fib(size_t n) {
  if(n <= 1) {
    return n;
  }
  return fib(n - 1) + fib(n - 2);
}

// FibVec Function Implementations
FibVec::FibVec(){
    this->fibn = 2;
    this->capa = fib(2);
    this->value = new int[capa];
    this->cnt = 0;
}

FibVec::~FibVec(){
    delete [] this->value;
}

size_t FibVec::capacity() const{
    return this->capa;
}

size_t FibVec::count() const{
    return this->cnt;
}

void FibVec::insert(int n, size_t index){
    if(index >= cnt){
        throw std::out_of_range("insert()");
    }
    if(this->cnt >= this->capa){
        resize_add();
    }
    for(size_t i = this->cnt; i > index; --i){
        this->value[i] = this->value[i - 1];
    }
    this->value[index] = n;
    this->cnt ++;
}

int FibVec::lookup(size_t index){
    if(index >= cnt){
        throw std::out_of_range("lookup()");
    }
    return this->value[index];
}

int FibVec::pop(){
    if(cnt == 0){
        throw std::underflow_error("pop()");
    }
    int temp = this->value[cnt - 1];
    cnt --;
    if(this->cnt < fib(fibn - 2)){
        resize_min();
    }
    return temp;
}

void FibVec::push(int n){
    if(this->cnt >= this->capa){
        resize_add();
    }
    this->value[cnt] = n;
    this->cnt ++;
}

int FibVec::remove(size_t index){
    if(index >= cnt){
        throw std::out_of_range("remove()");
    }
    int temp = this->value[index];
    for(int i = index; i < this->cnt - 1; ++i){
        this->value[i] = this->value[i + 1];
    }
    cnt --;
    if(this->cnt < fib(fibn - 2)){
        resize_min();
    }
    return temp;
}

void FibVec::resize_add(){
    this->fibn ++;
    int* temp = new int[this->capa];
    for(int i = 0; i < this->cnt; ++i){
        temp[i] = this->value[i];
    }
    delete[] this->value;
    this->value = temp;
}

void FibVec::resize_min(){
    this->fibn --;
    int* temp = new int[this->capa];
    for(int i = 0; i < this->cnt; ++i){
        temp[i] = this->value[i];
    }
    delete[] this->value;
    this->value = temp;
}