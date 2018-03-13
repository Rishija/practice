#include "btree.h"

/**
 * Time complexity : O(n)
 * Space complexity : O(height)
 */
template<class T>
bool Btree<T>::validate_sum(T k) {
    return validate_sum(root, k, 0);
}

template<class T>
bool Btree<T>::validate_sum(Node* node, const T required, T sum) {
    
    if(node == nullptr)
        return sum == required ? true : false;
    
    return validate_sum(node -> left, required, sum + node -> val) || validate_sum(node -> right, required, sum + node -> val);
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
    cout <<endl;
    cout<< tree.validate_sum(8) << endl;
    cout<< tree.validate_sum(5) << endl;
    cout<< tree.validate_sum(35) << endl;
    cout<< tree.validate_sum(87) << endl;
    cout<< tree.validate_sum(14) << endl;
    cout<< tree.validate_sum(36) << endl;
    cout<< tree.validate_sum(23) << endl;
    return 0;
}
