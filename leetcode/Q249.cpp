/*
 Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
 
 "abc" -> "bcd" -> ... -> "xyz"
 Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
 
 Example:
 
 Input: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"],
 Output:
 [
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
 ]
 */

vector<vector<string>> groupStrings(vector<string>& strings) {
    unordered_map<string, vector<string>> mapp;
    for(string str : strings) {
        string ans = "";
        for(int i = 0; i < str.size() - 1; ++i) {
            int gap = (str[i] - str[i+1] + 26) % 26;
            if(gap < 10) ans += "0";
            ans += gap;
        }
        mapp[ans].push_back(str);
    }
    
    vector<vector<string>> ans;
    for(auto it = mapp.begin(); it != mapp.end(); ++it) {
        ans.push_back(it->second);
    }
    return ans;
}
