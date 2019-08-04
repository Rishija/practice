/*
 There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
 
 Example 1:
 
 Input:
 [
 "wrt",
 "wrf",
 "er",
 "ett",
 "rftt"
 ]
 
 Output: "wertf"
 Example 2:
 
 Input:
 [
 "z",
 "x"
 ]
 
 Output: "zx"
 Example 3:
 
 Input:
 [
 "z",
 "x",
 "z"
 ]
 
 Output: ""
 
 Explanation: The order is invalid, so return "".
 Note:
 
 You may assume all letters are in lowercase.
 You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
 If the order is invalid, return an empty string.
 There may be multiple valid order of letters, return any one of them is fine.
 */

enum state {UNVISITED, VISITED, INPROCESS};
bool topologicalSort(unordered_map<char, state> &V, unordered_map<char, vector<char>> &G, char current, string &ans) {
    for(char &neighbour : G[current]) {
        if(V[neighbour] == INPROCESS)   return false;
        if(V[neighbour] == UNVISITED) {
            V[neighbour] = INPROCESS;
            if(topologicalSort(V, G, neighbour, ans) == false)  return false;
            V[neighbour] = VISITED;
        }
    }
    ans = current + ans;
    V[current] = VISITED;
    return true;
}

string alienOrder(vector<string>& words) {
    int n = words.size();   if(n < 1)   return "";
    if(n == 1)  { reverse(words[0].begin(), words[0].end()); return words[0]; }
    
    unordered_map<char, state> V;
    for(auto s : words) for(auto x : s) V[x] = UNVISITED;
    
    unordered_map<char, vector<char>> G;
    for(int i = 0; i < n-1; ++i) {
        string &A = words[i], &B = words[i+1];
        for(int j = 0; j < min(A.size(), B.size()); ++j)
            if(A[j] != B[j]) {  G[A[j]].push_back(B[j]); break; }
    }
    string ans;
    for(auto &pair : V) {
        if(pair.second == UNVISITED) {
            pair.second = INPROCESS;
            if(topologicalSort(V, G, pair.first, ans) == false)  return "";
            pair.second = VISITED;
        }
    }
    return ans;
}
