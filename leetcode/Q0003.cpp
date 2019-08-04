/*
 Given a string, find the length of the longest substring without repeating characters.
 
 Example 1:
 
 Input: "abcabcbb"
 Output: 3
 Explanation: The answer is "abc", which the length is 3.
 Example 2:
 
 Input: "bbbbb"
 Output: 1
 Explanation: The answer is "b", with the length of 1.
 Example 3:
 
 Input: "pwwkew"
 Output: 3
 Explanation: The answer is "wke", with the length of 3.
 Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

int lengthOfLongestSubstring(string s) {
    int n = s.size(); if(n < 2)   return n;
    unordered_map<char, int> map;
    int i = -1, j = 0, maxx = 0;
    while(j < n) {
        if(map.find(s[j]) != map.end())
            i = max(i, map[s[j]]);
        map[s[j]] = j;
        if(j - i > maxx) maxx = j - i;
        ++j;
    }
    return maxx;
}
