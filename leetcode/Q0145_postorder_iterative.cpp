/*
 Post order traversal
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Using 2 stack
 * Reverse of preorder iterative (interchange left and right nodes)
 */
vector<int> postorderTraversal(TreeNode* root) {
    
    vector<int> ans;
    if(root == nullptr)
        return ans;
    
    stack<TreeNode*> stack1;
    
    while(true) {
        while(root) {
            ans.insert(ans.begin(), root->val);
            stack1.push(root);
            root = root->right;
        }
        if(stack1.empty())
            break;
        root = stack1.top()->left;
        stack1.pop();
    }
    return ans;
}

/**
 * Using 1 stack
 * Change pointer to node->left until nullptr, Start checking top of stack. If top have no right child or right child is visited, push the value to ans and pop the element, else set node to node->right
 */
vector<int> preorderTraversal(TreeNode* root) {
    
    vector<int> ans;
    if(root == nullptr)
        return ans;
    
    stack<TreeNode*> stack1;
    TreeNode* lastPopped = nullptr;
    
    while(true) {
        while(root) {
            stack1.push(root);
            root = root->left;
        }
        if(stack1.empty())
            break;
        root = stack1.top();
        while(root->right == nullptr || root->right == lastPopped) {
            stack1.pop();
            lastPopped = root;
            ans.push_back(root->val);
            if(stack1.empty())
                return ans;
            root = stack1.top();
        }
        root = root->right;
    }
    return ans;
}

