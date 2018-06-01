/*
 You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 */
/*
 Time : O(n)
 Space : O(n)
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) {
    
    int n = s.size(), m = words.size();
    if(n == 0 || m == 0)    return {};
    
    int len = words[0].size(), left, end, start;
    vector<int> ans;
    string substr;
    long long int sum = 0;
    unordered_map<string, int> originalCount;
    
    for(int i = 0; i < m; ++i) {
        sum += words[i].size();
        if(sum > n) return ans;
        ++originalCount[words[i]];
    }
    
    for(int index = 0; index < n; ++index) {
        end = index + len; start = index; left = m;
        unordered_map<string, int> newCount;
        while(end < n+1 && left > 0) {
            substr = s.substr(start, end - start);
            if(originalCount[substr] > 0 && newCount[substr] + 1 <= originalCount[substr]) {
                ++newCount[substr];
                --left;
                start = end;
                end = start + len;
            }
            else    break;
        }
        if(left == 0)   ans.push_back(index);
    }
    return ans;
}


void print(string s, vector<string> &word) {
    vector<int> ans = findSubstring(s, word);
    for(int x : ans)
        cout << x << ", ";
    cout << endl;
}

int main() {
    
    vector<string> word;
    word = {"bar" ,"foo"};
    print("barfoothefoobarman", word);
    
    word = {"word","student"};
    print("wordgoodstudentgoodword", word);
    
    word = {"good" ,"good", "best", "word"};
    print("bestfoodbestgoodgoodword", word);
    
    word = {"good" ,"word", "best", "word"};
    print("bestfoodbestgoodgoodword", word);
    
    word = {"bar" ,"foo"};
    print("barbarfoobarman", word);
    return 0;
}
