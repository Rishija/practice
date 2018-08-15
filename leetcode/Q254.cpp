/*
Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
= 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
 
Example 1:
    Input: 1
    Output: []
 
Example 2:
    Input: 37
    Output:[]
 
Example 3:
    Input: 12
    Output:
    [
     [2, 6],
     [2, 2, 3],
     [3, 4]
    ]
 
Example 4:
    Input: 32
    Output:
    [
     [2, 16],
     [2, 2, 8],
     [2, 2, 2, 4],
     [2, 2, 2, 2, 2],
     [2, 4, 4],
     [4, 8]
    ]
*/

void helper(const int n, const int start, vector<int> &temp, vector<vector<int>> &ans) {
    if(n == 1)  {
        ans.push_back(temp);
        return;
    }
    for(int i = start; i <= n; ++i) {
        if(n % i == 0) {
            temp.push_back(i);
            helper(n/i, i, temp, ans);
            temp.pop_back();
        }
    }
}

vector<vector<int>> getFactors(int n) {
    if(n < 2)   return {};
    vector<int> temp;
    vector<vector<int>> ans;
    helper(n, 2, temp, ans);
    if(ans.size() < 2)  return {};
    ans.pop_back();
    return ans;
}
