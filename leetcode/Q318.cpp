/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
*/

int maxProduct(vector<string>& A) {
    int n = A.size();
    if(n < 2)
        return 0;
    
    int ans = 0;
    vector<int> hash(n);
    for(int i = 0; i < n; ++i) {
        for(char x : A[i])
            hash[i] |= 1 << (x - 'a');
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            int intersection = hash[i] & hash[j];
            if(intersection == 0 && A[i].size() * A[j].size() > ans)
                ans = A[i].size() * A[j].size();
        }
    }
    return ans;
}
