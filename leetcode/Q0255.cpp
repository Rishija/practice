/*
 Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.
 
 You may assume each number in the sequence is unique.
 
 Consider the following binary search tree:
 
      5
     / \
    2   6
   / \
  1   3
 
 Example 1:
     Input: [5,2,6,1,3]
     Output: false
 
 Example 2:
     Input: [5,2,1,3,6]
     Output: true
 
 Follow up:
 Could you do it using only constant space complexity?
 */

bool verifyPreorder(vector<int>& preorder) {
    stack<int> s;
    int min = INT_MIN;
    /*
     * At any time, element in the stack is in left subtree of all the elements below it
     * If current is less than stack.top(), push it in the stack, else pop elements till right position is found,
     ie., a list a nodes found of whose right subtree current resides
     * Everytime a node is popped out from stack, set `min = node`, because left subtree of popped element is over by now
     * Current value should be greater than min whenever new element is read from input
     */
    for(int x : preorder) {
        if(x <= min)    return false;
        while(!s.empty() && s.top() < x) {
            min = s.top();
            s.pop();
        }
        s.push(x);
    }
    return true;
}

// -------------------------------------------------------------------------------

/*
 Find index upto which elements are smaller than current node
 Check left && right subtree
 Start points to current node in `preorder`
 */
bool helper(int min, int max, vector<int> &order, int start, int end) {
    if(start > end) return true;
    // Check current element
    if(order[start] < min || order[start] > max)    return false;
    
    // Find index
    int i = start + 1;
    while(i <= end) {
        if(order[i] < min || order[i] > max)    return false;
        if(order[i] < order[start]) ++i;
        else break;
    }
    return helper(min, order[start] - 1, order, start + 1, i - 1) && helper(order[start] + 1, max, order, i, end);
}

bool verifyPreorder(vector<int>& preorder) {
    int n = preorder.size();
    if(n < 2)   return true;
    return helper(INT_MIN, INT_MAX, preorder, 0, n - 1);
}
