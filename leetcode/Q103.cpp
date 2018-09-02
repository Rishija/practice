/*
 Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

 For example:
 Given binary tree [3,9,20,null,null,15,7],
 3
 / \
 9  20
 /  \
 15   7
 return its zigzag level order traversal as:
 [
 [3],
 [20,9],
 [15,7]
 ]
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        bool flag = false;
        vector<vector<int>> ans;
        stack<TreeNode*> stack1;
        stack1.push(root);

        while(!stack1.empty()) {
            vector<int> temp;
            stack<TreeNode*> stack2;
            while(!stack1.empty()) {
                temp.push_back(stack1.top()->val);
                if(flag) {
                    if(stack1.top()->right != nullptr)  stack2.push(stack1.top()->right);
                    if(stack1.top()->left != nullptr)   stack2.push(stack1.top()->left);
                }
                else {
                    if(stack1.top()->left != nullptr)   stack2.push(stack1.top()->left);
                    if(stack1.top()->right != nullptr)  stack2.push(stack1.top()->right);
                }
                stack1.pop();
            }
            flag = !flag;
            ans.push_back(temp);
            stack1 = stack2;
        }
        return ans;
    }
};
