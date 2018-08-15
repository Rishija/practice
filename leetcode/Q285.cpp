/*
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

Note: If the given node has no in-order successor in the tree, return null.


Example 1:
Input: root = [2,1,3], p = 1

 2
/ \
1   3

Output: 2

Example 2:
Input: root = [5,3,6,2,4,null,null,1], p = 6

     5
    / \
   3   6
  / \
 2   4
/
1

Output: null
*/

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    if(root == nullptr) return nullptr;
    
    bool found = false;
    stack<TreeNode*> s;
    TreeNode* current = root;
    s.push(current);
    
    while(!s.empty()) {
        while(current) {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        if(s.empty())   return nullptr;
        if(found)       return current;
        if(current == p)    found = true;
        current = current->right;
    }
    return nullptr;
}

// ------------------------------------------------------

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
    TreeNode* ans = nullptr;
    while(root != nullptr) {
        // If p itself lies on the right subtree of current node
        if(root->val <= p->val) root = root->right;
        else {
            // Set ans to current temporarily and check if smaller can be found in left subtree
            ans = root;
            root = root->left;
        }
    }
    return ans;
}
