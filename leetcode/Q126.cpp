/*
Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:

Only one letter can be changed at a time
Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
Note:

Return an empty list if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
 ["hit","hot","dot","dog","cog"],
 ["hit","hot","lot","log","cog"]
 ]
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
*/

unordered_map<string,  unordered_set<string>> listt;
string endd;
void DFS(const string &start, vector<string> &temp, vector<vector<string>> &ans) {
    temp.push_back(start);
    if(start == endd) ans.push_back(temp);
    else              for(auto &next : listt[start]) DFS(next, temp, ans);
    temp.pop_back();
}

vector<vector<string>> findLadders(string A, string B, vector<string>& wordList) {
    if(wordList.empty())    return {};
    unordered_set<string> dict;
    for(auto &s : wordList) dict.insert(s);
    if(dict.find(B) == dict.end()) return {};
    dict.erase(A);
    endd = B;
    
    int len = wordList[0].size();
    bool found = false;
    unordered_set<string> thisMap;
    queue<string> q;
    q.push(A); q.push("");
    
    while(q.size() > 1) {
        string front = q.front(); q.pop();
        if(front == "") {
            for(const string &s : thisMap) dict.erase(s);
            thisMap.clear();
            q.push("");
            continue;
        }
        
        for(int i = 0; i < len; ++i) {
            string temp = front;
            for(char x = 'a'; x <= 'z'; ++x) {
                temp[i] = x;
                if(dict.find(temp) != dict.end()) {
                    thisMap.insert(temp);
                    if(temp == B)      found = true;
                    if(found == false) q.push(temp);
                    listt[front].insert(temp);
                }
            }
        }
    }
    if(found == false)  return {};
    vector<string> temp;
    vector<vector<string>> ans;
    DFS(A, temp, ans);
    return ans;
}
