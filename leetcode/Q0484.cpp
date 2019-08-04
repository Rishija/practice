/*
 By now, you are given a secret signature consisting of character 'D' and 'I'. 'D' represents a decreasing relationship between two numbers, 'I' represents an increasing relationship between two numbers. And our secret signature was constructed by a special integer array, which contains uniquely all the different number from 1 to n (n is the length of the secret signature plus 1). For example, the secret signature "DI" can be constructed by array [2,1,3] or [3,1,2], but won't be constructed by array [3,2,4] or [2,1,3,4], which are both illegal constructing special string that can't represent the "DI" secret signature.
 On the other hand, now your job is to find the lexicographically smallest permutation of [1, 2, ... n] could refer to the given secret signature in the input.
 */
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

/*
 Time : O(n^2)
 Space : O(n)
 */
vector<int> find_permutation(string input) {
    
    int n = input.size();
    if(n == 0)
        return {};
    if(n == 1)
        return {1};
    
    vector<int> ans;
    for(int i = 1; i <= n+1; ++i)
        ans.push_back(i);
    
    for(int i = 0; i < n; ++i) {
        if(input[i] == 'D') {
            int j = i;
            while(j < n && input[j] == 'D')
                ++j;
            reverse(ans.begin() + i, ans.begin() + j + 1);
            i = j - 1;
        }
    }
    return ans;
}

void print(string s) {
    vector<int> ans = find_permutation(s);
    for(auto x : ans)
        cout << x << " ";
    cout << endl;
}

int main() {
    
    string s = "DI";
    print(s);
    
    s = "III";
    print(s);
    
    s = "DDDD";
    print(s);
    
    s = "IDIDI";
    print(s);
    
    s = "DIIDD";
    print(s);
    
    return 0;
}
