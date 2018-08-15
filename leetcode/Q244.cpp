/*
Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “coding”, word2 = “practice”
Output: 3

Input: word1 = "makes", word2 = "coding"
Output: 1

Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
*/

class WordDistance {
    unordered_map<string, vector<int>> map;
public:
    WordDistance(vector<string> words) {
        for(int i = 0; i < words.size(); ++i)
            map[words[i]].push_back(i);
    }
    
    int shortest(string word1, string word2) {
        auto v1 = map.find(word1), v2 = map.find(word2);
        if(v1 == map.end() || v2 == map.end())  return -1;
        
        int n = v1->second.size(), m = v2->second.size(), ans = INT_MAX, i = 0, j = 0;
        while(i < n && j < m) {
            if(v1->second[i] < v2->second[j]) {
                ans = min(ans, v2->second[j] - v1->second[i]);
                ++i;
            }
            else {
                ans = min(ans, v1->second[i] - v2->second[j]);
                ++j;
            }
        }
        return ans;
    }
};
