/*
 Implement strStr().
 
 Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 
 Example 1:
 
 Input: haystack = "hello", needle = "ll"
 Output: 2
 Example 2:
 
 Input: haystack = "aaaaa", needle = "bba"
 Output: -1
 Clarification:
 
 What should we return when needle is an empty string? This is a great question to ask during an interview.
 
 For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
 */

int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    if(m > n)   return -1;
    if(m == 0)  return 0;
    
    int i = 0;
    while(i < n - m + 1) {
        if(haystack[i] == needle[0]) {
            int j = 1;
            while(j < m && haystack[i+j] == needle[j]) ++j;
            if(j == m)  return i;
        }
        ++i;
    }
    return -1;
}
