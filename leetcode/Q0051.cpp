/*
 The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
 
 Given an integer n, return all distinct solutions to the n-queens puzzle.
 
 Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
 
 Example:
 
 Input: 4
 Output: [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],
 
 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]
 Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
 */

bool isSafe(const int r, const int c, const int &A, const vector<pair<int, int>> &queens) {
    
    for(auto qPos : queens) {
        int row = qPos.first, col = qPos.second;
        if(r == row || c == col || row - col == r - c || row + col == r + c)
            return false;
    }
    return true;
}

void helper(vector<vector<string>> &ans, int col, const int &A, vector<pair<int, int>> &queens) {
    
    if(col == A) {
        vector<string> vec(A, string(A,'.'));
        for(auto qPos : queens)
            vec[qPos.first][qPos.second] = 'Q';
        ans.push_back(vec);
        return;
    }
    
    for(int i = 0; i < A; ++i) {
        if(isSafe(i, col, A, queens)) {
            queens.push_back({i,col});
            helper(ans, col + 1, A, queens);
            queens.pop_back();
        }
    }
}

class Solution {
public:
    vector<vector<string>> solveNQueens(int A) {
        if(A == 0)  return {};
        if(A == 1)  return {{"Q"}};
        if(A < 4)   return {};
        
        vector<vector<string>> ans;
        vector<pair<int, int>> queens;
        helper(ans, 0, A, queens);
        return ans;
    }
};
