#ifndef btree_h
#define btree_h

#include <iostream>
#include <queue>
#include <utility>
using namespace std;

template <class T>
class Btree {
public:
    class Node {
    public:
        T val;
        Node *left, *right;
        Node(T v = 0, Node* l = nullptr, Node* r = nullptr) : val(v), left(l), right(r) {}
    };
    
    Node* root;
    
    Btree() : root(nullptr) {}
    void insert(T data);
    void print_levelOrder();
    void even_odd_levelSum();
    
private:
    void insert(T, Node* &);
    void print_levelOrder(queue<Node*>);
    void even_odd_levelSum(pair<T,T> &, queue<Node*>, bool);
};

template<class T>
void Btree<T>::insert(T data) {
    insert(data, root);
}

template<class T>
void Btree<T>::insert(T data, Node* &node) {
    
    if(node == nullptr) {
        Node* neww = new Node(data);
        node = neww;
        return;
    }
    
    data < node -> val ? insert(data, node -> left) : insert(data, node -> right);
}

#endif /* btree_h */
