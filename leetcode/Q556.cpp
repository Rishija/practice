/*
 Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.
 
 Example 1:
 Input: 12
 Output: 21
 
 Example 2:
 Input: 21
 Output: -1
 */

int nextGreaterElement(int A) {
    if(A <= 11) return -1;
    string s;
    while(A != 0) {
        s += (A % 10) + 48;
        A /= 10;
    }
    
    reverse(s.begin(), s.end());
    int n = s.size(), i, j;
    
    for(i = n-2; i >= 0 && s[i] >= s[i+1]; --i);
    if(i == -1) return -1;
    
    for(j = n-1; s[j] <= s[i]; --j);
    swap(s[j], s[i]);
    reverse(s.begin() + i + 1, s.end());
    
    long long int ans = stol(s);
    if(ans > INT_MAX) return -1;
    return ans;
}
