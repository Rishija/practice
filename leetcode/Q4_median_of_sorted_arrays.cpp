double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int n = A.size(), m = B.size();
    if(n == 0) {
        if(m % 2 == 0)   return (B[m/2] + (double)B[m/2 - 1]) / 2;
        return B[m/2];
    }
    if(m == 0) {
        if(n % 2 == 0)   return (A[n/2] + (double)A[n/2 - 1]) / 2;
        return A[n/2];
    }
    
    if(A[n-1] <= B[0]) {
        int mid = (m + n)/2;
        if(mid == n) {
            if((m + n) % 2 == 0) return (A[n-1] + (double)B[0])/2;
            return B[0];
        }
        else if(mid < n) {
            if((m + n) % 2 == 0) return (A[mid-1] + (double)A[mid])/2;
            return A[mid];
        }
        else {
            mid -= n;
            if((m + n) % 2 == 0) return (B[mid-1] + (double)B[mid])/2;
            return B[mid];
        }
    }
    if(B[m-1] <= A[0]) {
        int mid = (m + n)/2;
        if(mid == m) {
            if((m + n) % 2 == 0) return (B[m-1] + (double)A[0])/2;
            return A[0];
        }
        else if(mid < m) {
            if((m + n) % 2 == 0) return (B[mid-1] + (double)B[mid])/2;
            return B[mid];
        }
        else {
            mid -= m;
            if((m + n) % 2 == 0) return (A[mid-1] + (double)A[mid])/2;
            return A[mid];
        }
    }
    
    const vector<int> &C = n >= m ? A : B, &D = n < m ? A : B;
    int low = 0, high = C.size() - 1, mid;
    while(low <= high) {
        mid = low + (high - low)/2;
        int dIndex = (m + n)/2 - mid - 1;
        
        if(dIndex > (int)D.size()) {
            low = mid + 1;
            continue;
        }
        if(dIndex < 0) {
            high = mid - 1;
            continue;
        }
        
        if(dIndex > 0 && C[mid+1] < D[dIndex - 1])  low = mid + 1;
        else if(dIndex < (int)D.size() && D[dIndex] < C[mid])   high = mid - 1;
        else {
            if((m + n) % 2 == 0) {
                int x = max(C[mid], D[dIndex - 1]), y = min(C[mid + 1], D[dIndex]);
                if(dIndex < 1)           x = C[mid];
                if(dIndex >= (int)D.size())   y = C[mid + 1];
                return (x + (double)y) / 2;
            }
            if(dIndex >= (int)D.size())
                return C[mid + 1];
            return min(C[mid + 1], D[dIndex]);
        }
    }
    return 0;
}
