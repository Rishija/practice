/*
 Remove the minimum number of invalid parentheses in order to make the input string valid. Return the length of the string. String only contains "(" and ")"
 */
#include <iostream>
#include <string>
using namespace std;

/*
 Time : O(n)
 Space : O(1)
 */
int longestValidParentheses(string s) {
    
    int n = s.size(), cnt = 0;
    
    for(char x : s) {
        if(x == '(')
            ++ cnt;
        if(x == ')') {
            if(cnt == 0)
                -- n;
            else
                -- cnt;
        }
    }
    return n - cnt;
}

int main() {
    
    string s = ")(";
    cout << longestValidParentheses(s) << endl;
    
    s = "()()(()";     // 6
    cout << longestValidParentheses(s) << endl;
    
    s = "(()))())(";     // 6
    cout << longestValidParentheses(s) << endl;
    
    s = ")()())()()(";   // 8
    cout << longestValidParentheses(s) << endl;
    
    s = "(()";
    cout << longestValidParentheses(s) << endl;
    
    s = "())";
    cout << longestValidParentheses(s) << endl;
    
    s = "((()())";      // 6
    cout << longestValidParentheses(s) << endl;
    
    s = "";
    cout << longestValidParentheses(s) << endl;
    
    s = "()(()";       // 4
    cout << longestValidParentheses(s) << endl;
    
    s = "(()))()";     // 6
    cout << longestValidParentheses(s) << endl;
    
    s = "(((";
    cout << longestValidParentheses(s) << endl;
    
    s = ")))";
    cout << longestValidParentheses(s) << endl;
    return 0;
}
