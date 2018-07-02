#include "btree.h"

/**
 * Time complexity : O(n)
 * Space complexity : O(height)
 */
template<class T>
typename Btree<T>::Node* Btree<T>::lca(T val1, T val2) {
    return lca(root, val1, val2);
}


// Both node values must be present in the tree
template<class T>
typename Btree<T>::Node* Btree<T>::lca(Node* node, T val1, T val2) {
    
    if(node == nullptr)
        return nullptr;
    
    if(node -> val == val1 || node -> val == val2)
        return node;
    
    Node *l = lca(node -> left, val1, val2), *r = lca(node -> right, val1, val2);

    if((l == nullptr) || (r == nullptr))
        return (l == nullptr) ? r : l;
 
    return node;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * Values may not be present in the tree
 
 
TreeNode* helper(TreeNode* node, int &found, const int B, const int C) {
    
    if(node == nullptr) return nullptr;
    
    // Search in left and right subtree
    TreeNode *foundInLeft = helper(node->left, found, B, C),
    *foundInRight = helper(node->right, found, B, C);
    
    // One more element found. Increase the counter
    if(node->val == B || node->val == C) {
        ++found;
        return node;
    }
    // If both subtrees have one of the required values
    if(foundInLeft && foundInRight) return node;
    // If any value is present in left subtree or right subtree
    return foundInLeft ? foundInLeft : foundInRight;
}

int lca(TreeNode* A, int B, int C) {
 
    int found = 0;
    TreeNode* ans = helper(A, found, B, C);
    // Both values are found in the tree
    if(found == 2)  return ans->val;
    // Value is present in the tree
    if(B == C && found == 1)    return B;
    return -1;
}
*/
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
    cout << endl;
    cout << tree.lca(90,101) -> val << endl;
    cout << tree.lca(87,1289) -> val << endl;
    cout << tree.lca(1006,90) -> val << endl;
    cout << tree.lca(61,17) -> val << endl;
    return 0;
}
