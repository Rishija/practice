/*
Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
 
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
 
Note:
- The value k is positive and will always be smaller than the length of the sorted array.
- Length of the given array is positive and will not exceed 104
- Absolute value of elements in the array and x will not exceed 104
*/

vector<int> method1(const vector<int> &A, int k, int x) {
    int n = A.size(), low = 0, high = n-1, mid;
    while(low <= high) {
        mid = low + (high - low) / 2;
        if(A[mid] == x)      break;
        else if(A[mid] < x)  low = mid + 1;
        else                 high = mid - 1;
    }
    
    vector<int> ans;
    ans.push_back(A[mid]);
    --k;
    int i = mid - 1, j = mid + 1;
    while(i >= 0 && j <= n-1 && k) {
        if(x - A[i] <= A[j] - x) ans.push_back(A[i--]);
        else                     ans.push_back(A[j++]);
        --k;
    }
    while(i >= 0 && k) {
        ans.push_back(A[i--]);
        --k;
    }
    while(j <= n-1 && k) {
        ans.push_back(A[j++]);
        --k;
    }
    sort(ans.begin(), ans.end());
    return ans;
}

vector<int> method2(const vector<int> &A, int k, int x) {
    int n = A.size(), low = 0, high = n-1, mid;
    while(low <= high) {
        mid = low + (high - low)/2;
        if(A[mid] == x) break;
        if(A[mid] < x)  low = mid + 1;
        else            high = mid - 1;
    }
    
    int i = max(0, mid - k + 1), j = min(n-1, mid + k - 1);
    while(j - i + 1 > k) {
        if(i < 0 || x - A[i] <= A[j] - x) --j;
        else ++i;
    }
    return vector<int> (A.begin() + i, A.begin() + i + k);
}

vector<int> method3(const vector<int> &A, int k, int x) {
    int n = A.size(), low = 0, high = n-1, mid;
    while(low <= high) {
        mid = low + (high - low)/2;
        if(A[mid] == x) break;
        if(A[mid] < x)  low = mid + 1;
        else            high = mid - 1;
    }
    
    // start is min possible start, end is max possible end
    int start = max(0, mid - k + 1), end = n - k - 1;
    while(start <= end) {
        mid = start + (end - start)/2;
        if(abs(A[mid + k] - x) < abs(A[mid] - x)) start = mid + 1;
        else end = mid - 1;
    }
    return vector<int> (A.begin() + start, A.begin() + start + k);
}

vector<int> findClosestElements(vector<int> &A, int k, int x) {
    // return method1(A, k, x);
    return method2(A, k, x);
    // return method3(A, k, x);
}
