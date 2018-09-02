/*
 Given an array of strings, group anagrams together.
 
 Example:
 
 Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
 Output:
 [
 ["ate","eat","tea"],
 ["nat","tan"],
 ["bat"]
 ]
 Note:
 
 All inputs will be in lowercase.
 The order of your output does not matter.
 */

vector<vector<string>> groupAnagrams(vector<string>& A) {
    int n = A.size();
    if(n == 0)   return {};
    if(n == 1)  return {A};
    
    unordered_map<string, vector<string>> map;
    for(auto &str : A) {
        int arr[26] = {0};
        for(char &x : str) arr[x-'a']++;
        string key;
        for(int i = 0; i < 26; ++i) key += to_string(arr[i]) + "*";
        map[key].push_back(str);
    }
    
    vector<vector<string>> ans;
    for(auto &p : map)   ans.push_back(p.second);
    return ans;
}
