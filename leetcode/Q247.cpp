/*
 A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
 
 Find all strobogrammatic numbers that are of length = n.
 
 Example:
 
 Input:  n = 2
 Output: ["11","69","88","96"]
*/

class Solution {
public:
    unordered_map<string,string> mapp;
    
    vector<string> helper(int n) {
        if(n == 0)  return {""};
        if(n == 1)  return {"0", "1", "8"};
        
        vector<string> prev = helper(n - 2), ans;
        // Add 0 as well as other numbers
        for(string str : prev)
            ans.push_back("0" + str + "0");
        for(string str : prev)
            for(auto it = mapp.begin(); it != mapp.end(); ++it)
                ans.push_back(it->first + str + it->second);
        return ans;
    }
    
    vector<string> findStrobogrammatic(int n) {
        if(n == 0)  return {};
        if(n == 1)  return {"0", "1", "8"};
        
        for(string x : {"1","8"}) mapp[x] = x; mapp["6"] = "9"; mapp["9"] = "6";
        
        // Do not add 0 as leading digit
        vector<string> ans, prev = helper(n - 2);
        for(string str : prev)
            for(auto it = mapp.begin(); it != mapp.end(); ++it)
                ans.push_back(it->first + str + it->second);
        
        return ans;
    }
};
