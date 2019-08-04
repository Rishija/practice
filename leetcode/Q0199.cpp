/*
 Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 Example:

 Input: [1,2,3,null,5,null,4]
 Output: [1, 3, 4]
 Explanation:

 1            <---
 /   \
 2     3         <---
 \     \
 5     4       <---

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
    // {level, node}
    using info = pair<int, TreeNode*>;

    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> ans;
        stack<info> s;
        info c = {0, root};

        while(true) {
            while(c.second != nullptr) {
                if(c.first == ans.size())
                    ans.push_back(c.second->val);
                s.push(c);
                c = {c.first + 1, c.second->right};
            }
            if(s.empty())
                break;
            c = s.top();
            s.pop();
            c = {c.first + 1, c.second->left};
        }
        return ans;
    }
};
