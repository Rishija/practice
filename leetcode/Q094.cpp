/*
 Given a binary tree, return the inorder traversal of its nodes' values.

 Example:

 Input: [1,null,2,3]
 1
 \
 2
 /
 3

 Output: [1,3,2]
 Follow up: Recursive solution is trivial, could you do it iteratively?
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == nullptr)
            return ans;

        stack<TreeNode*> stack;

        while(true) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            if(stack.empty())
                break;
            root = stack.top();
            stack.pop();
            ans.push_back(root->val);
            root = root->right;
        }
        return ans;
    }
};
