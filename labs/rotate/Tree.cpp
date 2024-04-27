#include <iostream>
#include <string>
#include "Tree.h"
#include "Node.h"
 size_t find_index(Node* curr, std::string input, size_t n, size_t temp1){
    if(curr == nullptr){
        return SIZE_MAX;
    }
    if((curr->left == nullptr && input < curr->data) || (curr->right == nullptr && input > curr->data)){
        return SIZE_MAX;
    }
    if(input < curr->data){
        if(input == curr->left->data){
            if(curr->left->left != nullptr){
                n = curr->left->left->weight;
                size_t temp = find_index(curr->left->left, input, 100, 0);
                if(temp > n){
                    return n;
                }
                else{
                    return temp;
                }
            }
            else{
                n = 0;
                return n;
            }
        }
        else{
            return find_index(curr->left, input, n, temp1);
        }
    }
    else if(input > curr->data){
        if(curr->left != nullptr){
            temp1 = curr->left->weight + 1;
        }
        else{
            temp1 ++;
        }
        if(input == curr->right->data){
            if(curr->right->left != nullptr){
                n = temp1 + curr->right->left->weight;
                size_t temp = find_index(curr->right->left, input, 100, 0);
                if(temp > n){
                    return n;
                }
                else{
                    return temp;
                }
            }
            else{
                return temp1;
            }
        }
        else{
            return find_index(curr->right, input, n, temp1);
        }
    }
    else{
        n = curr->left->weight;
        size_t temp = find_index(curr->left, input, 100, 0);
        if(temp > n){
            return n;
        }
        else{
            return temp;
        }
    }
}

// size_t find_index(Node* curr, const std::string& input) {
//     if (curr == nullptr) {
//         return SIZE_MAX;
//     }

//     if (input < curr->data) {
//         return find_index(curr->left, input);
//     } else if (input > curr->data) {
//         return find_index(curr->right, input);
//     } else {
//         size_t left_subtree_size = 0;
//         if (curr->left != nullptr) {
//             left_subtree_size = curr->left->weight + curr->right->left->weight + 1;
//         }
//         return left_subtree_size + 1;  // +1 for the current node (root of the subtree)
//     }
// }

Tree::Tree(){
    head = nullptr;
    cnt = 0;
}

Tree::~Tree(){
    clear();
}

void rec_clear(Node* curr){
    if (curr == nullptr) {
        return;
    }

    if (curr->left != nullptr) {
        rec_clear(curr->left);
        delete curr->left;
        curr->left = nullptr;
    }

    if (curr->right != nullptr) {
        rec_clear(curr->right);
        delete curr->right;
        curr->right = nullptr;
    }
}

void Tree::clear(){
    rec_clear(head);
    delete head;
    head = nullptr;
    cnt = 0;
}

size_t Tree::Tree::count() const{
    return cnt;
}

bool contains_rec(Node* curr, std::string input){
    if((input > curr->data) && (curr -> right != nullptr)){
        return contains_rec(curr->right, input);
    }
    else if((input < curr->data) && (curr ->left != nullptr)){
        return contains_rec(curr->left, input);
    }
    else if(((input > curr->data) && (curr -> right == nullptr))
            ||
            ((input < curr->data) && (curr -> left == nullptr))){
        return false;
    }
    else{
        return true;
    }
}

bool Tree::contains(const std::string& s) const{
    return contains_rec(head, s);
}

size_t Tree::find(const std::string& s) const{
    return find_index(head, s, 100, 0);
}

Node* insert_rec(Node* curr, const std::string input) {
    if (input > curr->data) {
        if (curr->right != nullptr) {
            return insert_rec(curr->right, input);
        } else {
            curr->weight ++;
            Node* newOne = new Node();
            newOne->data = input;
            (*curr).right = newOne;
            return newOne;
        }
    } else{
        if (curr->left != nullptr) {
            return insert_rec(curr->left, input);
        } else {
            curr->weight ++;
            Node* newOne = new Node();
            newOne->data = input;
            (*curr).left = newOne;
            return newOne;
        }
    }
}

void Tree::insert(const std::string& s){
    if(head == nullptr){
        Node* newOne = new Node();
        newOne->data = s;
        head = newOne;
        cnt ++;
    } else {
        insert_rec(head, s);
        cnt++;
    }
}


std::string Tree::lookup(size_t index) const{
    return "0";
}

std::string print_rec(Node* curr) {
    if (curr == nullptr) {
        return "-";
    } else if (curr->left == nullptr && curr->right == nullptr) {
        return curr->data;
    }else{
        std::string leftStr = print_rec(curr->left);
        std::string rightStr = print_rec(curr->right);
        return "(" + leftStr + " " + curr->data + " " + rightStr + ")";
    }
}

void Tree::print() const{
    std::cout << print_rec(head) << '\n';
}

void Tree::remove(size_t index){
    //情况1：没有children：直接remove，parent设为nullptr
    //情况2：有一个children：remove后把children接到上面那个
    //情况3：俩children：remove的对象->right->最左 替换到curr的位置
    
}
void Tree::promote(Node& node){}

