// Replace every node value with the sum of all its children nodes (all nodes below this)

#include "btree.h"
template<class T>
T Btree<T>::child_sum() {
    return child_sum(root);
}

template<class T>
T Btree<T>::child_sum(Node* &node) {
    
    if(node == nullptr)
        return 0;
    
    T value = node -> val;
    node -> val = child_sum(node->left) + child_sum(node->right);
    return value + node -> val;
    
    /* Bad appraoch
     
     T sum = 0;
     if(node -> left != nullptr) {
         sum += node -> left -> val + child_sum(node -> left);
     }
     if(node -> right != nullptr) {
         sum += node -> right -> val + child_sum(node -> right);
     }
     node -> val = sum;
     return node -> val;
     */
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
    cout<<endl<<endl;
    tree.child_sum();
    tree.print_levelOrder();
    return 0;
}
