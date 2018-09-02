/*
 Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 
 Example 1:
 
 Input: "babad"
 Output: "bab"
 Note: "aba" is also a valid answer.
 Example 2:
 
 Input: "cbbd"
 Output: "bb"
 */

string longestPalindrome(string s) {
    int n = s.size();
    if(n < 2)
        return s;
    string ans;
    ans.push_back(s[0]);
    
    for(int i = 0; i < n - 2; ++i) {
        if(s[i] == s[i+1]) {
            int j = i - 1, k = i + 2;
            while(j >= 0 && k < n && s[j] == s[k]) {
                --j;
                ++k;
            }
            if(ans.size() < k - j - 1)
                ans = s.substr(j + 1, k - j - 1);
        }
        if(s[i] == s[i+2]) {
            int j = i - 1, k = i + 3;
            while(j >= 0 && k < n && s[j] == s[k]) {
                --j;
                ++k;
            }
            if(ans.size() < k - j - 1)
                ans = s.substr(j + 1, k - j - 1);
        }
    }
    
    if(s[n-2] == s[n-1] && ans.size() < 2)
        ans = s.substr(n-2, 2);
    return ans;
}
