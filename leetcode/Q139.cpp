/*
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.

 Note:

 The same word in the dictionary may be reused multiple times in the segmentation.
 You may assume the dictionary does not contain duplicate words.
 Example 1:

 Input: s = "leetcode", wordDict = ["leet", "code"]
 Output: true
 Explanation: Return true because "leetcode" can be segmented as "leet code".
 Example 2:

 Input: s = "applepenapple", wordDict = ["apple", "pen"]
 Output: true
 Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
 Note that you are allowed to reuse a dictionary word.
 Example 3:

 Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 Output: false
 */

class Solution {
public:
    int helper(const string &A, int index, const unordered_map<string, bool> &map, vector<int> &dp, int minLen, int maxLen) {
        if(index == A.size())
            return 1;
        if(dp[index] == -1) {
            int len = minLen;
            bool ans = false;
            while(len <= maxLen && index + len <= A.size()) {
                if(map.find(A.substr(index,len)) != map.end())
                    ans |= helper(A, index + len, map, dp, minLen, maxLen);
                if(ans) break;
                len++;
            }
            dp[index] = ans;
        }
        return dp[index];
    }

    bool wordBreak(string A, vector<string>& B) {
        int n = A.size(), totalStr = B.size();

        unordered_map<string, bool> map;
        int minLen = INT_MAX, maxLen = 0;
        for(string str : B) {
            if(str.size() < minLen) minLen = str.size();
            if(str.size() > maxLen) maxLen = str.size();
            map[str] = true;
        }
        vector<int> dp(n+1, -1);
        return helper(A, 0, map, dp, minLen, maxLen);
    }
};
