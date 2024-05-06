#include <iostream>
#include <string>
#include "Tree.h"
#include "Node.h"

int get_weight(Node* curr){
    if(curr == nullptr){
        return 0;
    }
    else{
        return curr->weight;
    }
}

 size_t find_index(Node* curr, std::string input, size_t n){
    if(curr == nullptr){
        return SIZE_MAX;
    }
    if((curr->left == nullptr && input < curr->data) || (curr->right == nullptr && input > curr->data)){
        return SIZE_MAX;
    }
    if(input < curr->data){
        if(input == curr->left->data){
            n += get_weight(curr->left->left);
            size_t temp = find_index(curr->left->left, input, 0);
            if(temp != SIZE_MAX){
                return temp;
            }
            else{
                return n;
            }
        }
        else{
            return find_index(curr->left, input, n);
        }
    }
    else if(input > curr->data){
        n = n + get_weight(curr->left) + 1;
        if(input == curr->right->data){
            n += get_weight(curr->right->left);
            size_t temp = find_index(curr->right->left, input, 0);
            if(temp != SIZE_MAX){
                return n - 1;
            }
            else{
                return n;
            }
        }
        else{
            return find_index(curr->right, input, n);
        }
    }
    else{
        n += get_weight(curr->left);
        if(curr->left == nullptr){
            return n;
        }
        size_t temp = find_index(curr->left, input, 0);
        if(temp > n){
            return n;
        }
        else{
            return temp;
        }
    }
}


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
    if (curr == nullptr) {
        return false;
    }
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
    return find_index(head, s, 0);
}


void Tree::promote(Node* start, Node* curr){
    if(curr != nullptr){
        int imbalance2 = 0;
        int imbalance1 = std::abs(get_weight(start->left) - get_weight(start->right));
        if(curr->data > start->data){
            imbalance2 = std::abs(get_weight(curr->left) + get_weight(start->left) + 1 - get_weight(curr->right));
        }
        else{
            imbalance2 = std::abs(get_weight(curr->right) + get_weight(start->right) + 1 - get_weight(curr->left));
        }

        if(imbalance2 < imbalance1){
            if(start == head){
                // if(curr == start->right){
                //     curr->weight = curr->weight + get_weight(start->left) + 1;
                // }
                // if(curr == start->left){
                //     curr->weight = curr->weight + get_weight(start->right) + 1;
                // }
                curr->parent = nullptr;
                head = curr;
            }
            else{
                if(start == start->parent->right){
                    start->parent->right = curr;
                }
                else{
                    start->parent->left = curr;
                }
                curr->parent = start->parent;
            }
            if(curr == start->right){
                // if(curr != head){
                    curr->weight = curr->weight + get_weight(start->left) + 1;
                // }
                if(curr->left != nullptr){
                    curr->left->parent = start;
                }
                start->weight = get_weight(start->left) + get_weight(curr->left) + 1;
                start->right = curr->left;
                curr->left = start;
            }
            else{
                // if(curr != head){
                    curr->weight = curr->weight + get_weight(start->right) + 1;
                // }
                if(curr->right != nullptr){
                    curr->right->parent = start;
                }
                start->weight = get_weight(start->right) + get_weight(curr->right) + 1;
                start->left = curr->right;
                curr->right = start;
            }
            start->parent = curr;
        }
    }
}

Node* Tree::insert_rec(Node* curr, const std::string input) {
    if (input > curr->data) {
        if (curr->right != nullptr) {
            curr->weight ++;
            Node* temp = insert_rec(curr->right, input);
            promote(curr, curr->right);
            return temp;
        } else {
            curr->weight ++;
            Node* newOne = new Node();
            newOne->data = input;
            curr->right = newOne;
            newOne->parent = curr;
            promote(curr, curr->right);
            return newOne;
        }
    } else{
        if (curr->left != nullptr) {
            curr->weight ++;
            Node* temp = insert_rec(curr->left, input);
            promote(curr, curr->left);
            return temp;
        } else {
            curr->weight ++;
            Node* newOne = new Node();
            newOne->data = input;
            curr->left = newOne;
            newOne->parent = curr;
            promote(curr, curr->left);
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
        head->weight = cnt;
    }
}

size_t lookup_index(Node* curr, Node* target, size_t n){  //this function returns the index for Node target.
    if(curr == target){
        n += get_weight(curr->left);
        return n;
    }
    if(curr == nullptr){
        return SIZE_MAX;
    }
    // if((curr->left == nullptr && target->data < curr->data) || (curr->right == nullptr && target->data > curr->data)){
    //     return SIZE_MAX;
    // }
    if(target->data < curr->data){
        // if(target == curr->left){
        //     n += get_weight(curr->left->left);
        //     return n;
        // }
        // else{
        //     return lookup_index(curr->left, target, n); //the problem here
        // }
        return lookup_index(curr->left, target, n);
    }
    else if(target->data > curr->data){
        n = n + get_weight(curr->left) + 1;
        // if(target == curr->right){             //Q1: there is a seg fault for duplicate data. Can pointers be compared?
        //     n += get_weight(curr->right->left);
        //     return n;
        // }
        // else{
        //     return lookup_index(curr->right, target, n);
        // }
        return lookup_index(curr->right, target, n);
    }
    else{
        size_t l;
        size_t r;
        l = lookup_index(curr->left, target, n);
        n = n + get_weight(curr->left) + 1;
        r = lookup_index(curr->right, target, n);
        if(l > r){
            return r;
        }
        else{
            return l;
        }
        
    }
}


Node* Tree::lookup_rec(Node* curr, size_t index) const{
    size_t temp = lookup_index(head, curr, 0);
    // std::cout<<curr->data<<" index "<<temp<<" weight "<<curr->weight<<'\n';
    if(index > temp){
        return lookup_rec(curr->right, index);
    }
    else if(index < temp){
        return lookup_rec(curr->left, index);
    }
    else{
        return curr;
    }
}


std::string Tree::lookup(size_t index) const{
    if(index >= cnt){
        throw std::out_of_range("lookup()");
    }
    else{
        return lookup_rec(head, index)->data;
    }
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
 

Node* Tree::lookup_node(size_t index) const{
    return lookup_rec(head, index);
}

void Tree::remove(size_t index){
    if(index >= cnt){
        throw std::out_of_range("remove()");
    }
    Node* node = lookup_node(index);
    
    if(node == head){
        clear();
    }
    else{
        //先把weight更新一下
        Node* temp1 = node->parent;
        while(temp1 != nullptr){
            temp1->weight --;
            temp1 = temp1->parent;
        }
        //情况1：没有children：直接remove，parent设为nullptr
        if(node->left == nullptr && node->right == nullptr){
            if(node->data > node->parent->data){
                node->parent->right = nullptr;
                if(node->parent->left != nullptr){
                    promote(node->parent, node->parent->left);
                }
            }
            else{
                node->parent->left = nullptr;
                if(node->parent->right != nullptr){
                    promote(node->parent, node->parent->right);
                }
            }
            delete node;
        }
        
        //情况2：有一个children：remove后把children接到上面那个
        else if(node->left == nullptr && node->right != nullptr){
            // std::cout<<node->data<<'\n';
            if(node->data > node->parent->data){
                node->parent->right = node->right;
                node->right->parent = node->parent;
            }
            else{
                node->parent->left = node->right;
                node->right->parent = node->parent;
            }
            Node* temp = node->parent;
            while(temp != nullptr){
                if(node->data > temp->data && temp->left != nullptr){
                    // std::cout<<temp->data<<"  "<<temp->left->data<<'\n';
                    promote(temp, temp->left);
                }
                else if(node->data <= temp->data && temp->right != nullptr){
                    // std::cout<<temp->data<<"  "<<temp->right->data<<'\n';
                    promote(temp, temp->right);
                }
                temp = temp->parent;
            }

            delete node;
        }
        else if(node->left != nullptr && node->right == nullptr){
            // std::cout<<node->data<<'\n';
            if(node->data > node->parent->data){
                node->parent->right = node->left;
                node->left->parent = node->parent;
            }
            else{
                node->parent->left = node->left;
                node->left->parent = node->parent;
            }
            Node* temp = node->parent;
            while(temp != nullptr){
                if(node->data > temp->data && temp->left != nullptr){
                    // std::cout<<temp->data<<"  "<<temp->left->data<<'\n';
                    promote(temp, temp->left);
                }
                else if(node->data <= temp->data && temp->right != nullptr){
                    // std::cout<<temp->data<<"  "<<temp->right->data<<'\n';
                    promote(temp, temp->right);
                }
                temp = temp->parent;
            }
            delete node;
        }

        //情况3：俩children：remove的对象->right->最左 替换到curr的位置
        else{
            Node* temp = node->right;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            if(node->right == temp){
                if(node == node->parent->right){
                    node->parent->right = temp;
                }
                else{
                    node->parent->left = temp;
                }
                temp->left = node->left;
                temp->parent = node->parent;
                delete node;
            }
            else if(temp->right != nullptr && node->right != temp){
                temp->right->right = node->right;
                node->right = temp->right;
                temp->right->parent = node;
                temp->parent->left = nullptr;
                node->right->parent = temp->right;
                node->data = temp->data;
                delete temp;
            }
            else{
                node->data = temp->data;
                temp->parent->left = nullptr;
                delete temp;
            }
        }
        cnt --;
    }
    //promotion target: 
    // if(curr->right != nullptr){
    //     promote(curr,curr->right->data);
    // }
    // else{
    //     promote(curr,curr->data);
    // }
}


