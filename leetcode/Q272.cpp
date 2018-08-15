/*
 Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
 
 Note:
 
 Given target value is a floating point.
 You may assume k is always valid, that is: k ≤ total nodes.
 You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
 Example:
 
 Input: root = [4,2,5,1,3], target = 3.714286, and k = 2
 
    4
   / \
  2   5
 / \
 1   3
 
 Output: [4,3]
 
 Follow up:
 Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?
 */

queue<int> q;

void helper(TreeNode* node, const double &target, const int &k) {
    if(node == nullptr) return;
    
    helper(node->left, target, k);
    
    // List not yet complete
    if(q.size() < k)    q.push(node->val);
    // Distance is decreasing
    else if(abs(target - q.front()) > abs(target - node->val)) {
        q.pop();
        q.push(node->val);
    }
    // Distance have started to increase
    else    return;
    
    helper(node->right, target, k);
}

vector<int> closestKValues(TreeNode* root, double target, int k) {
    if(k == 0)  return {};
    helper(root, target, k);
    vector<int> ans;
    while(!q.empty()) {
        ans.push_back(q.front());
        q.pop();
    }
    return ans;
}
