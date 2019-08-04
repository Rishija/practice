/*
 Given two strings s and t, determine if they are both one edit distance apart.
 
 Note:
 
 There are 3 possiblities to satisify one edit distance apart:
 
 Insert a character into s to get t
 Delete a character from s to get t
 Replace a character of s to get t
 */

bool isOneEditDistance(string s, string t) {
    int n = s.size(), m = t.size();
    if(abs(n - m) > 1)      return false;
    if(n == 0 && m == 0)    return false;
    if(n == 0 || m == 0)    return true;
    
    bool used = false;
    int i = 0, j = 0;
    for(i = 0, j = 0; i < n && j < m; ++i, ++j) {
        if(s[i] != t[j]) {
            if(used)    return false;
            if(n > m)       --j;
            else if(m > n)  --i;
            used = true;
        }
    }
    if(i < n || j < m)  return !used;
    return used;
}
