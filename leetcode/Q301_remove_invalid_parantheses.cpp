/*
 Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
 
 Note: The input string may contain letters other than the parentheses ( and ).
 */
#include <iostream>
#include <stack>
#include <queue>
#include <stack>
#include <vector>
#include <set>
using namespace std;

bool isValid(string s) {
    
    if(s.size() < 1)
        return true;
    
    int count = 0;
    for(char ch : s) {
        if(ch == '(')
            ++ count;
        else if(ch == ')')
            -- count;
        
        if(count < 0)
            return false;
    }
    return count == 0;
}
/*
 Time : Exponential
 Space : O(n)
 */

vector<string> removeInvalidParentheses(string s) {
    
    if(s.size() == 0)
        return {""};
    
    vector<string> ans;
    queue<string> queue;
    set<string> set;
    bool found = false;
    
    queue.push(s);
    set.insert(s);
    
    while(!queue.empty()) {
        
        string temp = queue.front();
        if(isValid(temp)) {
            ans.push_back(temp);
            found = true;
        }
        queue.pop();
        
        if(found)
            continue;
        
        for(int i = 0; i < temp.size(); i++) {
            
            if (!(temp[i] == '(') && !(temp[i] == ')'))
                continue;
            
            // find substring
            string substr = temp.substr(0, i) + temp.substr(i+1, temp.size());
            
            if(set.find(substr) == set.end()) {
                queue.push(substr);
                set.insert(substr);
            }
        }
    }
    return ans;
}

void print(string s) {
    
    vector<string> ans = removeInvalidParentheses(s);
    for(string str : ans)
        cout << str << " ";
    cout << endl;
}

int main() {
    
    string s;
    
    s = "()())()";
    print(s);
    
    s = "()(()()";
    print(s);
    
    s = "(a)())()";
    print(s);
    
    s = "(()))((()";
    print(s);
    
    s = "((()";
    print(s);
    
    s = "()))";
    print(s);
    
    s = "()((((((()l(";
    print(s);
    
    s = "(a(";
    print(s);
    
    s = "()a";
    print(s);
    
    s = ")a";
    print(s);
    
    s = "()()()()))()";
    print(s);
    
    s = "a";
    print(s);
    
    s = "a(";
    print(s);
    
    s = ")a(";
    print(s);
    
    s = ")(";
    print(s);
    
    s = ")";
    print(s);
    
    s = "(";
    print(s);
    
    return 0;
}
