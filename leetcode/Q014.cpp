/*
 Write a function to find the longest common prefix string amongst an array of strings.
 
 If there is no common prefix, return an empty string "".
 
 Example 1:
 
 Input: ["flower","flow","flight"]
 Output: "fl"
 Example 2:
 
 Input: ["dog","racecar","car"]
 Output: ""
 Explanation: There is no common prefix among the input strings.
 Note:
 
 All given inputs are in lowercase letters a-z.
 */

string longestCommonPrefix(vector<string>& strs) {
    int n = strs.size();
    if(n == 0)
        return "";
    
    string prefix(strs[0]);
    int len = prefix.size();
    for (int strNum = 1; strNum < n; ++strNum) {
        int length = min((int)strs[strNum].size(), len);
        for (int i = 0; i < length; ++i) {
            if(prefix[i] != strs[strNum][i]) {
                len = i;
                break;
            }
        }
        len = min(len, length);
    }
    return prefix.substr(0, len);
}
