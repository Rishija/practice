#include "btree.h"

/**
 * Time complexity : O(n)
 * Sapce complexity : O(height)
 */
template<class T>
typename Btree<T>::Node* Btree<T>::tree_to_dll() {
    Node* head, *par = nullptr;
    tree_to_dll(root, par, head);
    return head;
}

template<class T>
void Btree<T>::tree_to_dll(Node* node, Node* &parent, Node* &head) {
    
    if(node == nullptr)
        return;
    
    tree_to_dll(node -> left, parent, head);
    
    // left most node
    if(parent == nullptr)
        head = node;
    else {
        parent -> right = node;
        node -> left = parent;
    }
    parent = node;
    
    tree_to_dll(node -> right, parent, head);
}

int main() {
    Btree<int>tree;
    tree.insert(5);
    tree.insert(2);
    tree.insert(10);
    tree.insert(1);
    tree.insert(3);
    tree.insert(8);
    tree.insert(4);
    tree.insert(7);
    tree.insert(6);
    tree.insert(20);
    tree.print_levelOrder();
    
    Btree<int>::Node* head = tree.tree_to_dll();
    
    while(head != nullptr) {
        cout << head -> val << " ";
        head = head -> right;
    }
    return 0;
}
