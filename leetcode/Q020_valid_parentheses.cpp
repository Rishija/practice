/*
 Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 
 The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */
/*
 Time, space : O(n)
 */
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

bool isValid(string s) {
    
    int n = s.size();
    if(!n)
        return true;
    if(n % 2)
        return false;
    
    map<char,char> map;
    map[')'] = '(';
    map['}'] = '{';
    map[']'] = '[';
    
    stack<char>stack;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            stack.push(s[i]);
        else {
            
            if(stack.size() == 0 || map[s[i]] != stack.top())
                return false;
            stack.pop();
            
            /*
            if(stack.size() &&
               ((s[i] == ')' && stack.top() == '(') ||
                (s[i] == '}' && stack.top() == '{') ||
                (s[i] == ']' && stack.top() == '[') ) )
                
                stack.pop();
            else
                return false;
             */
        }
    }
    return stack.empty();
}

int main() {
    
    string s = "()";
    cout << isValid(s) << endl;
    
    s = "()[]{}";
    cout << isValid(s) << endl;
    
    s = "({[]})";
    cout << isValid(s) << endl;
    
    s = "[{()()}({{}})]";
    cout << isValid(s) << endl;
    
    s = "(]";
    cout << isValid(s) << endl;
    
    s = "([)]";
    cout << isValid(s) << endl;
    
    s = "}]";
    cout << isValid(s) << endl;
    
    s = "((";
    cout << isValid(s) << endl;
    
    return 0;
}

