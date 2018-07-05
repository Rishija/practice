/*
 Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
 */

typedef pair<int,int> pii;

struct hashFn {
    size_t operator () (const pii &p) const {
        auto h1 = std::hash<int>{}(p.first);
        auto h2 = std::hash<int>{}(p.second);
        return h1 ^ h2;
    }
};

using Mapp = unordered_map<pii, int, hashFn>;

int helper(Mapp &dp, const string &S, const string &P, int i, int j) {
    
    if(dp.find({i,j}) == dp.end()) {
        int ans;
        if(i == S.size() && j == P.size())
            ans = 1;
        else if(j == P.size())
            ans = 0;
        else if(i == S.size()) {
            if((P.size() - j) % 2)
                ans = 0;
            else
                ans = P[j + 1] == '*' && helper(dp, S, P, i, j + 2);
        }
        // Next character is '*'
        else if(j < P.size() - 1 && P[j+1] == '*') {
            // Current current matched
            if(P[j] == S[i] || P[j] == '.')
                ans = helper(dp, S, P, i + 1, j) || helper(dp, S, P, i, j + 2);
            else
                ans = helper(dp, S, P, i, j + 2);
        }
        else if(P[j] == S[i] || P[j] == '.')
            ans = helper(dp, S, P, i + 1, j + 1);
        else
            ans = 0;
        dp[{i,j}] = ans;
    }
    return dp[{i,j}];
}

bool isMatch(string A, string B) {
    int n = A.size(), m = B.size();
    Mapp dp;
    return helper(dp, A, B, 0, 0);
}

/* Without DP
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
 */

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
