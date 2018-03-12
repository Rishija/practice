#include "btree.h"

template <class T>
bool Btree<T>::isBST(T low, T high) {
    return isBST(root, low, high);
}

template <class T>
bool Btree<T>::isBST(Node* node, T low, T high) {
    
    if(node == nullptr)
        return true;
    
    if(node -> val < low || node -> val > high)
        return false;
    
    /* In case of repitition, duplicate value goes on the right child of the node
     So high reduces to ( current_value - 1 ) on left subtree
     */
    return isBST(node -> left, low, node -> val - 1) && isBST(node -> right, node -> val, high);
}

int main() {
    Btree<int>tree;
    tree.insert(87);
    tree.insert(34);
    tree.insert(64);
    tree.insert(12);
    tree.insert(673);
    tree.insert(98);
    tree.insert(33);
    tree.insert(1);
    tree.insert(39);
    tree.insert(90);
    tree.insert(101);
    tree.insert(147);
    tree.insert(13);
    tree.insert(48);
    tree.insert(61);
    tree.insert(82);
    tree.insert(17);
    tree.insert(537);
    tree.insert(1006);
    tree.insert(289);
    tree.insert(27);
    tree.print_levelOrder();
    cout<<endl;
    cout << tree.isBST(INT_MIN, INT_MAX) << endl;
    tree.root -> left -> val = 9999;
    cout << tree.isBST(INT_MIN, INT_MAX) << endl;
    return 0;
}
