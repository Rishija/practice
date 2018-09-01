/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:
Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input:
[
 [1, 2, 3, 4],
 [5, 6, 7, 8],
 [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
*/

vector<int> spiralOrder(vector<vector<int>>& A) {
    int n = A.size();
    if(n == 0)
        return {};
    int m = A[0].size(), r1 = 0, r2 = n-1, c1 = 0, c2 = m-1, count = 0;
    vector<int> ans;
    do{
        switch(count){
            case 0:
                for(int i = c1; i <= c2; ++i)
                    ans.push_back(A[r1][i]);
                ++r1;
                ++count;
                break;
            case 1:
                for(int i = r1; i <= r2;++i)
                    ans.push_back(A[i][c2]);
                --c2;
                ++count;
                break;
            case 2:
                for(int i = c2; i >= c1; --i)
                    ans.push_back(A[r2][i]);
                --r2;
                ++count;
                break;
            case 3:
                for(int i = r2; i >= r1; --i)
                    ans.push_back(A[i][c1]);
                ++c1;
                count = 0;
                break;
        }
    } while(r1<=r2 && c1<=c2);
    return ans;
}
