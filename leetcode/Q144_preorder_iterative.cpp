/*
 Pre order traversal
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode* root) {
    
    
    vector<int> ans;
    if(root == nullptr)
        return ans;
    
    stack<TreeNode*> stack1;
    TreeNode* current  = root;
    while(true) {
        while(current != nullptr) {
            ans.push_back(current->val);
            stack1.push(current);
            current = current->left;
        }
        if(stack1.size() == 0)
            break;
        current = stack1.top();
        stack1.pop();
        current = current->right;
    }
    return ans;
}

