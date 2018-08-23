/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2]
Output: 1

Example 2:
Input: [4,5,6,7,0,1,2]
Output: 0
*/

int method1(const vector<int> &A, int low, int high) {
    if(low == high) return A[low];
    if(A[low] < A[high])    return A[low];
    int mid = low + (high - low) / 2;
    if(A[mid] >= A[low]) return method1(A, mid + 1, high);
    return method1(A, low, mid);
}

int method2(const vector<int> &A) {
    int low = 0, high = A.size() - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        if(A[mid] > A[high]) low = mid + 1;
        else                 high = mid;
    }
    return A[low];
}

int findMin(vector<int>& A) {
    int n = A.size();
    // return method1(A, 0, n-1);
    return method2(A);
}
