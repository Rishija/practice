/*
 Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 */

bool isMatch(string s, string p) {
    
    int n = s.size(), m = p.size();
    
    if(m == 0)
        return n == 0 ? true : false;
    
    int pIndex = 0, i;
    
    for(i = 0; i < n && pIndex < m; ++i) {
        if(pIndex < m - 1 && p[pIndex + 1] == '*') {
            return isMatch(s.substr(i, string::npos), p.substr(pIndex + 2, string::npos)) // didn't match
            || ((p[pIndex] == s[i] || p[pIndex] == '.') && isMatch(s.substr(i + 1, string::npos), p.substr(pIndex, string::npos)));    // match
        }
        else if(p[pIndex] == s[i] || p[pIndex] == '.')
            pIndex += 1;
        else
            return false;
    }
    
    if(i == n) {
        if((m - pIndex) % 2)
            return false;
        for(int i = pIndex + 1; i < m; i += 2)
            if(p[i] != '*')
                return false;
        return true;
    }
    else
        return false;
}

int main() {
    //     1
    //     1
    //     0
    //     1
    //     1
    //     1
    //     0
    //     1
    //     0
    //     1
    //     1
    //     0
    //     0
    //     1
    //
    //     0
    //     1
    //     1
    //
    //     1
    //     0
    //     1
    //     0
    cout << isMatch("", "c*b*") << endl;
    cout << isMatch("a", "ab*") << endl;
    cout << isMatch("aa", "a") << endl;
    cout << isMatch("aaaa", "a*") << endl;
    cout << isMatch("ab", ".*") << endl;
    cout << isMatch("aab", "c*a*b") << endl;
    cout << isMatch("mississippi", "mis*is*p*.") << endl;
    cout << isMatch("aaabbb", "a*b*") << endl;
    cout << isMatch("abcd", "*b*") << endl;
    cout << isMatch("hello", ".*") << endl;
    cout << isMatch("hello", "h.ll.*") << endl;
    cout << isMatch("hello", ".*cy") << endl;
    cout << isMatch("aaaaaab", "a*a*a*c") << endl;
    cout << isMatch("aaaaaab", "a*a*a*b") << endl;
    
    cout << endl;
    cout << isMatch("aaa", "aaaa") << endl;
    cout << isMatch("aaa", "ab*a*c*a") << endl;
    cout << isMatch("abcdefghijkl", ".*ef.*") << endl;
    
    cout << endl;
    cout << isMatch("hello", "h.*o") << endl;
    cout << isMatch("hello", "h.*l") << endl;
    cout << isMatch("hello", ".*o") << endl;
    cout << isMatch("hello", ".*l") << endl;
    
    return 0;
}
