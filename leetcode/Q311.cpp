/*
Given two sparse matrices A and B, return the result of AB.

You may assume that A's column number is equal to B's row number.

Example:

Input:

A = [
     [ 1, 0, 0],
     [-1, 0, 3]
     ]

B = [
     [ 7, 0, 0 ],
     [ 0, 0, 0 ],
     [ 0, 0, 1 ]
     ]

Output:

A = | 1 0 0 |
    | -1 0 3 |
 
B = | 7 0 0 |
    | 0 0 0 |
    | 0 0 1 |
 
AB = | 7 0 0|
     |-7 0 3|
*/


vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size(), m = A[0].size(), p = B[0].size();
    vector<vector<int>> ans(n, vector<int>(p));
    vector<unordered_map<int, bool>> nonZeroCols(p);
    for(int j = 0; j < p; ++j) for(int i = 0; i < m; ++i)
        if(B[i][j] != 0)    nonZeroCols[j][i] = true;
    
    for(int i = 0; i < n; ++i) {
        unordered_map<int, bool> nonZeroRows;
        for(int j = 0; j < m; ++j) if(A[i][j] != 0) nonZeroRows[j] = true;
        
        for(auto aRow : nonZeroRows) for(int k = 0; k < p; ++k)
            if(nonZeroCols[k].find(aRow.first) != nonZeroCols[k].end())
                ans[i][k] += A[i][aRow.first] * B[aRow.first][k];
    }
    return ans;
}

// ----------------------------------------------------------------------------

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
    int n = A.size(), m = A[0].size(), p = B[0].size();
    
    vector<vector<int>> ans(n, vector<int>(p));
    vector<unordered_set<int>> nonZeroCols(p);
    for(int j = 0; j < p; ++j) for(int i = 0; i < m; ++i)
        if(B[i][j] != 0)    nonZeroCols[j].insert(i);
    
    
    for(int i = 0; i < n; ++i) {
        unordered_set<int> nonZeroRows;
        for(int j = 0; j < m; ++j) if(A[i][j] != 0) nonZeroRows.insert(j);
        
        for(auto aRow : nonZeroRows) for(int k = 0; k < p; ++k)
            if(nonZeroCols[k].find(aRow) != nonZeroCols[k].end())
                ans[i][k] += A[i][aRow] * B[aRow][k];
    }
    return ans;
}
