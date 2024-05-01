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


bool promote(Node* start, Node* curr, std::string target){
    if(curr != nullptr){
        int imbalance2 = 0;
        int imbalance1 = std::abs(get_weight(start->left) - get_weight(start->right));
        
        if(target > curr->data){
            Node* tempParent = curr->parent;
            while(true){
                imbalance2 += get_weight(tempParent->left) + 1;
                if(tempParent == start){
                    break;
                }
                tempParent = tempParent->parent;
            }
            imbalance2 = std::abs(imbalance2 + get_weight(curr->left) - get_weight(curr->right));
        }
        else if(target < curr->data){
            Node* tempParent = curr->parent;
            while(true){
                imbalance2 += get_weight(tempParent->left) + 1;
                if(tempParent == start){
                    break;
                }
                tempParent = tempParent->parent;
            }
            imbalance2 = std::abs(imbalance2 + get_weight(curr->right) - get_weight(curr->left));
        }
        else{
            if(target > curr->parent->data){
                Node* tempParent = curr->parent;
                while(true){
                    imbalance2 += get_weight(tempParent->left) + 1;
                    if(tempParent == start){
                        break;
                    }
                    tempParent = tempParent->parent;
                }
                imbalance2 = std::abs(imbalance2 + get_weight(curr->left) - get_weight(curr->right));
            }
            else if(target < curr->parent->data){
                Node* tempParent = curr->parent;
                while(true){
                    imbalance2 += get_weight(tempParent->left) + 1;
                    if(tempParent == start){
                        break;
                    }
                    tempParent = tempParent->parent;
                }
                imbalance2 = std::abs(imbalance2 + get_weight(curr->right) - get_weight(curr->left));
            }
        }

        // std::cout<<imbalance1<<"/"<<imbalance2<<'\n';
        if(imbalance2 < imbalance1){
            Node* temp = curr->parent; //Q2: temp keeps goes up to every parent between target and promotion head.
            while(true){
                Node* temp2 = curr; //temp2 goes all the way left or right and finally points to the most left of right node.
                if(temp->data <= curr->data){
                    while(temp2->left != nullptr){
                        temp2 = temp2->left;
                    }
                    temp2->left = temp;   //I'm so confused why I'm getting seg fault here. (pretty sure it's between line 220-227)
                }
                else{
                    while(temp2->right != nullptr){
                        temp2 = temp2->right;
                    }
                    temp2->right = temp;
                }
                if(temp->parent == start){
                    break;
                }
                temp = temp->parent;
            }
            curr->parent = nullptr;
            return true;
        }
        else{
            if(target > curr->data){
                promote(start, curr->right, target);
            }
            else{
                promote(start, curr->left, target);
            }
        }
    }
    return false;
}

Node* insert_rec(Node* curr, const std::string input) {
    if (input > curr->data) {
        if (curr->right != nullptr) {
            curr->weight ++;
            Node* temp = insert_rec(curr->right, input);
            // std::cout<<"promote "<<curr->data<<'\n';
            // promote(curr, curr->right, input);
            return temp;
        } else {
            curr->weight ++;
            Node* newOne = new Node();
            newOne->data = input;
            curr->right = newOne;
            curr->right->parent = curr;
            // std::cout<<"promote "<<curr->data<<'\n';
            // promote(curr, curr->right, input);
            return newOne;
        }
    } else{
        if (curr->left != nullptr) {
            curr->weight ++;
            Node* temp = insert_rec(curr->left, input);
            // promote(curr, curr->left, input);
            return temp;
        } else {
            curr->weight ++;
            Node* newOne = new Node();
            newOne->data = input;
            curr->left = newOne;
            curr->left->parent = curr;
            // promote(curr, curr->left, input);
            return newOne;
        }
    }
}

// Node* insert_rec(Node* curr, const std::string input) {
//     if (input > curr->data) {
//         if (curr->right != nullptr) {
//             Node* temp = insert_rec(curr->right, input);
//             std::cout<<"promote "<<curr->right->data<<'\n';
//             promote(curr, curr->right, input);
//             return temp;
//         } else {
//             curr->weight ++;
//             Node* newOne = new Node();
//             newOne->data = input;
//             curr->right = newOne;
//             curr->right->parent = curr;
//             std::cout<<"promote "<<curr->right->data<<'\n';
//             promote(curr, curr->right, input);
//             return newOne;
//         }
//     } else{
//         if (curr->left != nullptr) {
//             Node* temp = insert_rec(curr->left, input);
//             promote(curr, curr->left, input);
//             return temp;
//         } else {
//             curr->weight ++;
//             Node* newOne = new Node();
//             newOne->data = input;
//             curr->left = newOne;
//             curr->left->parent = curr;
//             promote(curr, curr->left, input);
//             return newOne;
//         }
//     }
// }


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
        
        // if(curr->left == nullptr){
        //     return n;
        // }
        // n += curr->left->weight;
        // size_t temp = lookup_index(curr->left, target, 0);
        // if(temp > n){
        //     return n;
        // }
        // else{
        //     return temp;
        // }
    }
}


Node* Tree::lookup_rec(Node* curr, size_t index) const{
    size_t temp = lookup_index(head, curr, 0);
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
    if(index >= cnt){
        throw std::out_of_range("lookup()");
    }
    else{
        return lookup_rec(head, index);
    }
}

void Tree::remove(size_t index){
    if(index >= cnt){
        throw std::out_of_range("lookup()");
    }
    Node* node = lookup_node(index);
    
    if(node == head){
        clear();
    }
    else{
        //情况1：没有children：直接remove，parent设为nullptr
        if(node->left == nullptr && node->right == nullptr){
            if(node->data > node->parent->data){
                node->parent->right = nullptr;
            }
            else{
                node->parent->left = nullptr;
            }
            delete node;
        }
        
        //情况2：有一个children：remove后把children接到上面那个
        else if(node->left == nullptr && node->right != nullptr){
            if(node->data > node->parent->data){
                node->parent->right = node->right;
                node->right->parent = node->parent;
            }
            else{
                node->parent->left = node->right;
                node->right->parent = node->parent;
            }
            delete node;
        }
        else if(node->left != nullptr && node->right == nullptr){
            if(node->data > node->parent->data){
                node->parent->right = node->left;
                node->left->parent = node->parent;
            }
            else{
                node->parent->left = node->left;
                node->left->parent = node->parent;
            }
            delete node;
        }

        //情况3：俩children：remove的对象->right->最左 替换到curr的位置
        else{
            Node* temp = node->right;
            while(temp->left != nullptr){
                temp = temp->left;
            }
            node->data = temp->data;
            temp->parent->left = nullptr;
            delete temp;
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


