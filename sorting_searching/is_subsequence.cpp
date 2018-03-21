/*
 Given a string s and a string t, check if s is subsequence of t.
 */
#include <iostream>
#include <string>
using namespace std;
/*
 Time : O(n)
 Space : O(1)
 */
bool isSubsequence(string sequence, string subsequence) {
    
    int n = sequence.size(), m = subsequence.size();
    
    if(!m)
        return true;
    
    if(m > n)
        return false;
    
    int i = 0, j = 0;
    while(i < n && j < m) {
        if(sequence[i] == subsequence[j]) {
            ++ i;
            ++ j;
        }
        else
            ++ i;
    }
    
    return j == m ? true : false;
}

int main() {
    
    string a = "ds", b = "da";
    cout << isSubsequence(a, b) << endl;
    
    a = ""; b = "sf";
    cout << isSubsequence(a, b) << endl;
    
    a = "fsf"; b = "";
    cout << isSubsequence(a, b) << endl;
    
    a = "abcdef"; b = "acd";
    cout << isSubsequence(a, b) << endl;
    
    a = "abcdef"; b = "f";
    cout << isSubsequence(a, b) << endl;
    
    a = "abcd"; b = "dc";
    cout << isSubsequence(a, b) << endl;
    
    a = "aaaab"; b = "aa";
    cout << isSubsequence(a, b) << endl;
    
    a = "abababa"; b = "baa";
    cout << isSubsequence(a, b) << endl;
}
