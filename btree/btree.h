#ifndef btree_h
#define btree_h

#include <iostream>
#include <queue>
#include <utility>
#include <stack>
#include <map>
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
    void level_sum();
    T child_sum();
    void alt_level_order();
    void diameter();
    bool isBST(T low, T high);
    void alt_level_order_stack();
    int diameter_simple();
    Node* lca(T val1, T val2);
    bool validate_sum(T k);
    Node* tree_to_dll();
    void tree_to_dll(Node*, Node* &, Node* &);
    void print_vertical();
    T kSmallest(size_t k);
    
private:
    void insert(T, Node* &);
    void print_levelOrder(queue<Node*>);
    void even_odd_levelSum(pair<T,T> &, queue<Node*>, bool);
    void even_odd_levelSum(Node*, T[2], int);
    void level_sum(queue<Node*>, int);
    T child_sum(Node* &);
    void alt_level_order(deque<Node*>, bool);
    pair<int,int> diameter(Node*);
    bool isBST(Node* node, T low, T high);
    int diameter_simple(Node* node, int &diameter);
    Node* lca(Node* node, T val1, T val2);
    bool validate_sum(Node*, const T, T);
    void print_vertical(Node*, int, map<int, vector<Node*> > &);
    Node* kSmallest(Node*, size_t &, size_t, bool);
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

template<class T>
void Btree<T>::print_levelOrder() {
    
    if(root == nullptr)
        return;
    
    queue<Node*> myQueue;
    myQueue.push(root);
    print_levelOrder(myQueue);
}

template<class T>
void Btree<T>::print_levelOrder(queue<Node*> inQueue) {
    
    if(!inQueue.size())
        return;
    
    queue<Node*> outQueue;
    while(inQueue.size() > 0){
        Node* thisNode = inQueue.front();
        cout << thisNode -> val << " ";
        if(thisNode -> left != nullptr)
            outQueue.push(thisNode -> left);
        if(thisNode -> right != nullptr)
            outQueue.push(thisNode -> right);
        inQueue.pop();
    }
    cout << endl;
    print_levelOrder(outQueue);
}

#endif /* btree_h */
