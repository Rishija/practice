/*
Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.

word1 and word2 may be the same and they represent two individual words in the list.

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = “makes”, word2 = “coding”
Output: 1

Input: word1 = "makes", word2 = "makes"
Output: 3

Note:
You may assume word1 and word2 are both in the list.
*/

int shortestWordDistance(vector<string>& words, string word1, string word2) {
    int n = words.size();
    if(n < 2)   return -1;
    int p1 = -1, p2 = -1, ans = INT_MAX;
    
    if(word1 == word2) {
        for(int i = 0; i < n; ++i) {
            if(words[i] == word1) {
                if(p1 != -1)
                    ans = min(ans, i - p1);
                p1 = i;
            }
        }
    }
    else {
        for(int i = 0; i < n; ++i) {
            if(words[i] == word1)       p1 = i;
            else if(words[i] == word2)  p2 = i;
            if(p1 != -1 && p2 != -1)    ans = min(ans, abs(p1 - p2));
        }
    }
    return ans == INT_MAX ? -1 : ans;
}
