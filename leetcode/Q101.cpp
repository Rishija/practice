/*
 Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 Approach: Check if every level is a palindrome
 Limitation: Memory Limit exceeded
 
bool isSymmetric(TreeNode* root) {
    
    if(root == nullptr)
        return true;
    
    bool allNull;
    TreeNode* current;
    vector<TreeNode*> first;
    first.push_back(root);
    
    while(true) {
        vector<TreeNode*> second;
        allNull = true;
        int index = 0, n = first.size();
        while(index < n) {
            current = first[index];
            if(current != nullptr) {
                allNull = false;
                second.push_back(current->left);
                second.push_back(current->right);
            }
            else {
                second.push_back(nullptr);
                second.push_back(nullptr);
            }
            ++index;
        }
        if(allNull)
            break;
        int nn = second.size();
        
        for(int i = 0; i <= nn/2; ++i) {
            if((second[i] == nullptr && second[nn-i-1] != nullptr) || (second[nn-i-1] == nullptr && second[i] != nullptr))
                return false;
            if(second[i] != second[nn-i-1] && second[i]->val != second[nn-i-1]->val)
                return false;
        }
        first = second;
    }
    return true;
}
 */

bool helper(TreeNode* n1, TreeNode* n2) {
    if(n1 == nullptr)
        return n2 == nullptr ? true : false;
    if(n2 == nullptr)
        return false;
    return n1->val == n2->val && helper(n1->left, n2->right) && helper(n1->right, n2->left);
}
bool isSymmetric(TreeNode* root) {
    
    if(root == nullptr)
        return true;
    return helper(root->left, root->right);
}

int main() {
    
    std::ios::sync_with_stdio(false);
    
    TreeNode* root = new TreeNode(-64);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    
    cout << isSymmetric(root) << endl;
    
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(3);
    
    cout << isSymmetric(root) << endl;
    return 0;
}

