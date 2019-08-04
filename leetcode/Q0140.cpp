/*
 Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.

 Note:

 The same word in the dictionary may be reused multiple times in the segmentation.
 You may assume the dictionary does not contain duplicate words.
 Example 1:

 Input:
 s = "catsanddog"
 wordDict = ["cat", "cats", "and", "sand", "dog"]
 Output:
 [
 "cats and dog",
 "cat sand dog"
 ]
 Example 2:

 Input:
 s = "pineapplepenapple"
 wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 Output:
 [
 "pine apple pen apple",
 "pineapple pen apple",
 "pine applepen apple"
 ]
 Explanation: Note that you are allowed to reuse a dictionary word.
 Example 3:

 Input:
 s = "catsandog"
 wordDict = ["cats", "dog", "sand", "and", "cat"]
 Output:
 []
 */

class Solution {
public:
    unordered_set<string> dict;
    unordered_map<string, vector<string>> dp;

    void helper(const string &s) {
        if(dp.find(s) != dp.end())      return;
        if(dict.find(s) != dict.end())  dp[s].push_back(s);

        for(int len = 1; len < s.size(); ++len) {
            string start = s.substr(0, len);
            if(dict.find(start) != dict.end()) {
                string rest = s.substr(len);
                helper(rest);
                for(auto &ss : dp[rest]) dp[s].push_back(start + " " + ss);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int m = wordDict.size();    if(m == 0)  return {};
        for(auto &s : wordDict) dict.insert(s);
        helper(s);
        return dp[s];
    }
};
