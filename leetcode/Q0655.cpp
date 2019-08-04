/*
 Print a binary tree in an m*n 2D string array following these rules:
 
 - The row number m should be equal to the height of the given binary tree.
 - The column number n should always be an odd number.
 - The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
 Each unused space should contain an empty string "".
 Print the subtrees following the same rules.
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<string>> printTree(TreeNode* root) {
    
    if(root == nullptr)
        return {};
    
    bool allNull;
    vector<vector<string>> ans;
    TreeNode* current;
    queue<TreeNode*> first;
    first.push(root);
    
    while(true) {
        queue<TreeNode*> second;
        vector<string> temp;
        allNull = true;
        while(!first.empty()) {
            current = first.front();
            first.pop();
            if(current != nullptr) {
                allNull = false;
                temp.push_back(to_string(current -> val));
                second.push(current->left);
                second.push(current->right);
            }
            else {
                temp.push_back("");
                second.push(nullptr);
                second.push(nullptr);
            }
            temp.push_back("");
        }
        if(allNull)
            break;
        first = second;
        temp.pop_back();
        ans.push_back(temp);
    }
    
    int index = 0;
    for(int row = ans.size() - 1; row > 0; --row, ++index) {
        vector<string> x(pow(2,row) - 1, ""), y = x;
        for(auto str : ans[index]) {
            x.push_back(str);
            x.insert(x.end(), y.begin(), y.end());
        }
        ans[index] = x;
    }
    return ans;
}

int main() {
    
    std::ios::sync_with_stdio(false);
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    
    //    TreeNode* root = new TreeNode(1);
    //    root->left = new TreeNode(2);
    //    root->right = new TreeNode(3);
    //    root->left->right = new TreeNode(5);
    
    //    TreeNode* root = new TreeNode(1);
    //    root->left = new TreeNode(2);
    //    root->right = new TreeNode(5);
    //    root->left->left = new TreeNode(3);
    //    root->left->left->left = new TreeNode(4);
    printTree(root);
    return 0;
}

