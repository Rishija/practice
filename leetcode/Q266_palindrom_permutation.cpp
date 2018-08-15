/*
 Given a string, determine if a permutation of the string could form a palindrome.
 
 Example 1:
 
 Input: "code"
 Output: false
 Example 2:
 
 Input: "aab"
 Output: true
 Example 3:
 
 Input: "carerac"
 Output: true
*/

bool canPermutePalindrome(string s) {
    unordered_map<char, bool> map;
    for(char x : s) map[x] = !map[x];
    bool found = false;
    for(auto p : map) {
        if(map[p.first] == true) {
            if(found)   return false;
            found = true;
        }
    }
    return true;
}
