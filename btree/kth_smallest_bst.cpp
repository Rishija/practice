/*
 Find kth smallest element in a BST
 
 Time : O(n)
 Space : O(height)
 */
#include "btree.h"

template<class T>
T Btree<T>::kSmallest(size_t k) {
    
    if(k < 1) {
        return (T)NULL;
    }
    
    size_t cnt = 0;
    
    Node* temp = kSmallest(root, cnt, k, true);
    
    return temp == nullptr ? (T)NULL : temp -> val;
}

template<class T>
typename Btree<T>::Node* Btree<T>::kSmallest(Node* node, size_t &count, size_t k, bool leftCall) {
    
    if(node == nullptr) {
        return node;
    }
    
    Node* left = kSmallest(node -> left, count, k, true);
    
    if(left != nullptr)
        return left;
    
    ++ count;
    
    if(count == k)
        return node;
    
    return kSmallest(node -> right, count, k, false);
}

int main() {
    
    int temp;
    Btree<int> tree;
    tree.insert(50);
    tree.insert(20);
    tree.insert(10);
    tree.insert(1);
    tree.insert(30);
    tree.insert(80);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(5);
    
    for(int i = 0; i < 13; ++i) {
        temp = tree.kSmallest(i);
        temp ? cout << i << " -> " << temp : cout << "Invalid";
        cout << endl;
    }
    return 0;
}
