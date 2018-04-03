/*
 Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
 
 For example:
 
 Given s = "aabb", return ["abba", "baab"].
 
 Given s = "abc", return [].
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

pair<int,char> is_palindrome_permutation(string s) {
    
    int n = s.size();
    if(n < 2)
        return {1, s[0]};
    
    map<char, int> check;
    int cnt = 0;
    
    for(char x : s) {
        check[x] ^= 1;
        check[x] ? ++cnt : --cnt;
    }
    
    char oddChar;
    for(auto x : check)
        if(x.second) {
            oddChar = x.first;
            break;
        }
    
    if(cnt == 0)
        return {0,'-'};
    if(cnt == 1)
        return {1, oddChar};
    return {-1, '-'};
}

void helper(vector<vector<char> > &ans, vector<char> temp, int index, int n, string source, bool isOdd = false, char oddChar = '-') {
    
    if(index > n/2 && !isOdd) {
        ans.push_back(temp);
        return;
    }
    if(index == n/2 && isOdd) {
        temp[index] = oddChar;
        ans.push_back(temp);
        return;
    }
    
    for(int i = 0; i < source.size(); ++i) {
        
        string newSource = source.substr(0,i);
        if(i != source.size() - 2)
            newSource += source.substr(i+2, source.size() - i - 1);
        
        temp[index] = source[i];
        temp[n - index] = source[i];
        
        helper(ans, temp, index + 1, n, newSource, isOdd, oddChar);
        
        char current = source[i];
        while(i < source.size() && source[i] == current)
            ++i;
        -- i;
    }
    
}
vector<vector<char> > palindrome_permuation(string s) {
    
    int n = s.size();
    if(n == 0)
        return {};
    if(n == 1) {
        vector<char> temp;
        temp.push_back(s[0]);
        return {temp};
    }
    
    pair<int,char> status = is_palindrome_permutation(s);
    if(status.first == -1)
        return {};
    
    sort(s.begin(), s.end());
    vector<vector<char> >ans;
    vector<char> temp(n);
    
    if(status.first == 1) {
        int oddIndex = s.find(status.second);
        string t = s.substr(0, oddIndex);
        t += s.substr(oddIndex + 1, n - oddIndex - 1);
        helper(ans, temp, 0, n - 1, t, true, status.second);
    }
    else
        helper(ans, temp, 0, n - 1, s);
    
    return ans;
}

ostream& operator << (ostream &os, vector<char> v) {
    
    cout << "[ ";
    for(char x : v)
        os << x;
    cout << " ]";
    return os;
}

void print(string s) {
    vector<vector<char> > ans = palindrome_permuation(s);
    for(auto x : ans)
        cout << x << endl;
    cout << endl;
}

int main() {
    
    string s = "abbac";
    print(s);
    
    s = "abba";
    print(s);
    
    s = "abc";
    print(s);
    
    return 0;
}

