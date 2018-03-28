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
    
    int n = s.size();
    if(!n)
        return 1;
    
    stack<char> stack;
    
    for(char ch : s) {
        if(ch == '(') {
            stack.push(ch);
        }
        else if(ch == ')') {
            if(stack.empty() || stack.top() != '(')
                return 0;
            stack.pop();
        }
    }
    return stack.empty();
}
/*
 Time : Exponential
 Space : O(n)
 */
vector<string> removeInvalidParentheses(string s) {
    
    int n = s.size();
    if(!n)
        return {""};
    
    if(isValid(s))
        return {s};
    
    string current, subString;
    bool found = false;
    vector<string> ans;
    set<string> set;
    
    queue<string> queue1;
    queue1.push(s);
    
    while(!queue1.empty() && !found) {
        queue<string> temp;
        while(!queue1.empty()) {
            current = queue1.front();
            queue1.pop();
            for(int i = 0; i < current.size(); ++i) {
                subString = current.substr(0, i) + current.substr(i+1, current.size());
                if(isValid(subString)) {
                    set.insert(subString);
                    found = true;
                }
                temp.push(subString);
            }
        }
        queue1 = temp;
    }
    if(set.size() == 0)
        return {""};
    
    for(string str : set)
        ans.push_back(str);
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
