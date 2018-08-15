/*
 Given two 1d vectors, implement an iterator to return their elements alternately.
 
 Example:
 
 Input:
 v1 = [1,2]
 v2 = [3,4,5,6]
 
 Output: [1,3,2,4,5,6]
 
 Explanation: By calling next repeatedly until hasNext returns false,
 the order of elements returned by next should be: [1,3,2,4,5,6].
 Follow up: What if you are given k 1d vectors? How well can your code be extended to such cases?
 
 Clarification for the follow up question:
 The "Zigzag" order is not clearly defined and is ambiguous for k > 2 cases. If "Zigzag" does not look right to you, replace "Zigzag" with "Cyclic". For example:
 
 Input:
 [1,2,3]
 [4,5,6,7]
 [8,9]
 
 Output: [1,4,8,2,5,9,3,6,7].
 */

class ZigzagIterator {
public:
    vector<vector<int>> A;
    int k;
    int current;
    vector<int> index;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : A(2), k(2), current(0), index(k) {
        A[0] = v1;
        A[1] = v2;
    }
    
    int next() {
        
        int ele = A[current][index[current]];
        index[current]++;
        current++;
        if(current == k)    current = 0;
        return ele;
    }
    
    bool hasNext() {
        
        int start = current;
        bool entered = false;
        while(index[current] >= A[current].size()) {
            ++current;
            entered = true;
            if(current == k)    current = 0;
            if(current == start)    break;
        }
        if(entered && current == start)    return false;
        return true;
    }
};
