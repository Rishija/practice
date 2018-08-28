/*
 Given a string, find the length of the longest substring T that contains at most k distinct characters.

Example 1:
Input: s = "eceba", k = 2
Output: 3
Explanation: T is "ece" which its length is 3.

Example 2:
Input: s = "aa", k = 1
Output: 2
Explanation: T is "aa" which its length is 2.
*/

int lengthOfLongestSubstringKDistinct(string s, int K) {
    int n = s.size();
    if(n == 0 || K == 0)  return 0;
    
    unordered_map<char,int> map;
    int done = 0, i = 0, j, ans = 0;
    
    for(j = 0; j < n; ++j) {
        if(++map[s[j]] == 1) // Character entered
            ++done;
        while(done > K)
            if(--map[s[i++]] == 0) // Character left
                --done;
        if(j - i + 1 > ans)
            ans = j - i + 1;
    }
    return ans;
}
