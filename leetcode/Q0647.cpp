/*
 Given a string, your task is to count how many palindromic substrings in this string.

 The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

 Example 1:
 Input: "abc"
 Output: 3
 Explanation: Three palindromic strings: "a", "b", "c".
 Example 2:
 Input: "aaa"
 Output: 6
 Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 Note:
 The input string length won't exceed 1000.
 */

class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0, n = s.size();

        for(int i = 0; i < n-1; ++i) {
            if(s[i] == s[i+1]) {
                int j = i, k = i + 1;
                while(j >= 0 && k < n && s[j] == s[k]) { --j; ++k; }
                cnt += i - j;
            }
        }

        for(int i = 0; i < n-2; ++i) {
            if(s[i] == s[i+2]) {
                int j = i, k = i + 2;
                while(j >= 0 && k < n && s[j] == s[k]) { --j; ++k; }
                cnt += i - j;
            }
        }
        cnt += n;
        return cnt;
    }
};
