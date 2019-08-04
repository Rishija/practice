/*
 Given a pattern and a string str, find if str follows the same pattern.
 
 Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
 
 Example 1:
 Input: pattern = "abab", str = "redblueredblue"
 Output: true
 
 Example 2:
 Input: pattern = pattern = "aaaa", str = "asdasdasdasd"
 Output: true
 
 Example 3:
 Input: pattern = "aabb", str = "xyzabcxzyabc"
 Output: false
 
 Notes:
 You may assume both pattern and str contains only lowercase letters.
 */

unordered_map<char, string> map1;
unordered_map<string, char> map2;
string pattern, str;

bool helper(int p1, int s1) {
    
    if(p1 >= pattern.size() || s1 >= str.size())
        return p1 == pattern.size() && s1 == str.size();
    
    for(int i = s1 + 1; i <= str.size(); ++i) {
        const string req = str.substr(s1, i-s1);
        auto it2 = map2.find(req);
        auto it1 = map1.find(pattern[p1]);
        // Both mapping exists, both must match
        if(it1 != map1.end() && it2 != map2.end())
            return map1[pattern[p1]] == req && map2[req] == pattern[p1] && helper(p1+1, s1+req.size());
        
        // No mapping exists
        if(it1 == map1.end() && it2 == map2.end()) {
            // Create new mapping
            map1[pattern[p1]] = req;
            map2[req] = pattern[p1];
            if(helper(p1+1, i))   return true;
            map2.erase(req);
            map1.erase(pattern[p1]);
        }
    }
    return false;
}

bool wordPatternMatch(string P, string S) {
    pattern = P;
    str = S;
    return helper(0, 0);
}

// ----------------------------------------------------------------

unordered_map<char, string> map1;
unordered_map<string, char> map2;
bool helper(const string &pattern, const string &str, int p1, int s1) {
    
    if(p1 == pattern.size() && s1 == str.size()) return true;
    if(p1 >= pattern.size() || s1 >= str.size()) return false;
    
    for(int i = s1 + 1; i <= str.size(); ++i) {
        string req = str.substr(s1, i-s1);
        
        // Both mapping exists, both must match
        if(map2.find(req) != map2.end() && map1.find(pattern[p1]) != map1.end())
            return map1[pattern[p1]] == req && map2[req] == pattern[p1] && helper(pattern, str, p1+1, s1+req.size());
        
        // One side mapping exists
        if(map2.find(req) != map2.end() || map1.find(pattern[p1]) != map1.end())
            continue;
        
        // Create new mapping
        map1[pattern[p1]] = req;
        map2[req] = pattern[p1];
        if(helper(pattern, str, p1+1, i))   return true;
        map2.erase(req);
        map1.erase(pattern[p1]);
    }
    return false;
}

bool wordPatternMatch(string pattern, string str) {
    // map1.clear();
    // map2.clear();
    return helper(pattern, str, 0, 0);
}
