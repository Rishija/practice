/*
 Let's call any (contiguous) subarray B (of A) a mountain if the following properties hold:
 
 B.length >= 3
 There exists some 0 < i < B.length - 1 such that B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B[B.length - 1]
 (Note that B could be any subarray of A, including the entire array A.)
 
 Given an array A of integers, return the length of the longest mountain.
 
 Return 0 if there is no mountain.
 */

int longestMountain(vector<int>& A) {
    
    int n = A.size();
    if(n < 3)
        return 0;
    int max = 0;
    
    for(int i = 0; i < n - max + 1; ++i) {
        int j = i + 1;
        while(j < n && A[j] > A[j - 1])
            ++j;
        if(j == i + 1)
            continue;
        int k = j;
        while(k < n && A[k] < A[k - 1])
            ++k;
        if(k == j)
            continue;
        if(k - i > max)
            max = k - i;
    }
    return max;
}
