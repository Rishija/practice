/*
 Given two strings s and t, determine if they are isomorphic.

 Two strings are isomorphic if the characters in s can be replaced to get t.

 All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

 Example 1:

 Input: s = "egg", t = "add"
 Output: true
 Example 2:

 Input: s = "foo", t = "bar"
 Output: false
 Example 3:

 Input: s = "paper", t = "title"
 Output: true
 Note:
 You may assume both s and t have the same length.
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size(), m = t.size();
        if(n != m || n < 2 || m < 2)
            return true;
        unordered_map<char,char> map1, map2;

        for(int i = 0; i < n; ++i) {
            if(map1.find(s[i]) == map1.end()) {
                if(map2.find(t[i]) != map2.end())
                    return false;
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
                continue;
            }
            if(map2.find(t[i]) == map2.end())
                return false;

            else if(map1[s[i]] != t[i] || map2[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
