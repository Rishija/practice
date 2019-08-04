/*
 Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 */
/*
 Time : O(n)
 Space : O(n)
 */
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t) {
    
    int n = s.size(), m = t.size();
    string ans = s;
    
    if(n == 0 || n < m) return "";
    if(m == 0)  return s.substr(0, 1);
    
    unordered_map<char, int> required, positions;
    vector<int> possibleStart;
    for(char x : t)  ++required[x];
    
    int start = 0, current = 0, done = m, ansStart = 0, len = n, curLen;
    while(current < n+1) {
        if(required[s[current]] > 0) {
            possibleStart.push_back(current);
            ++positions[s[current]];
            if(positions[s[current]] > required[s[current]]) {
                while(positions[s[possibleStart[start]]] > required[s[possibleStart[start]]]) {
                    --positions[s[possibleStart[start]]];
                    ++start;
                }
            }
            else
                --done;
            
            curLen = current - possibleStart[start] + 1;
            if(done == 0 && curLen < len) {
                ansStart = possibleStart[start];
                len = curLen;
                if(len == m)
                    return s.substr(ansStart, len);
                while(positions[s[possibleStart[start]]] > required[s[possibleStart[start]]]) {
                    --positions[s[possibleStart[start]]];
                    ++start;
                }
            }
        }
        ++current;
    }
    return done == 0 ? s.substr(ansStart, len) : "";
}

int main() {
    
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    return 0;
}
