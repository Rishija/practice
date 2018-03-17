#include <iostream>
#include <string>
#include <map>
using namespace std;

bool isPermutation(string s, string t) {
    
    int n = s.size(), m = t.size();
    if(n != m)
        return false;
    
    map<char,int> record;
    for(int i = 0; i < n; ++i)
        ++ record[s[i]];
    
    for(int i = 0; i < m; ++i) {
        if(!record[t[i]])
            return false;
        -- record[t[i]];
    }
    return true;
}

int main() {
    
    string a = "abcdaaac";
    cout << isPermutation(a, "") << endl;
    cout << isPermutation(a, "abcdaaac") << endl;
    cout << isPermutation(a, "caaadcba") << endl;
    cout << isPermutation(a, "mflkfklr") << endl;
    cout << isPermutation(a, "dabbcaac") << endl;
    cout << isPermutation(a, "ccdaaabb") << endl;
    cout << isPermutation("a", "a") << endl;
    cout << isPermutation("a", "b") << endl;
    return 0;
}
