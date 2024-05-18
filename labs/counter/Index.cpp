#include "Index.h"

// Index Member Functions

// Index::Index(){
//     for(int i = 0; i < 10000; ++i){
//         hashTable[i] = new Node*[1000];
//         hashTable_cnt[i] = 0;
//     }
// }
// int Index::hashFunction(std::string str) const{
//     int ret;
//     for (char c : str) {
//         ret += static_cast<int>(c);
//     }
//     return ret % 10000;
// }

// void Index::insert(Node* node){
//     int hashIndex = hashFunction(node->key);
//     int collIndex = hashTable_cnt[hashIndex];
//     hashTable[hashIndex][collIndex] = node;
//     collIndex ++;
// }