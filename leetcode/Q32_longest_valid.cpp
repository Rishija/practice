/*
 Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
 */

#include <iostream>
#include <tuple>
using namespace std;

/*
 Time : O(n)
 Space : O(n)
 */

// When closing braces appear before opening braces
tuple<int, string, int> helper(string s) {
    
    int n = s.size(), last = 0, maxx = 0, cnt = 0;
    string t;
    
    for(int i = 0; i < n; ++i) {
        
        if(s[i] == '(') {
            ++ cnt;
            t = ")" + t;
        }
        else if(s[i] == ')') {
            maxx = max(maxx, i - last + 1);
            
            // problem index
            if(cnt == 0) {
                last = i + 1;
                
                // add ")" to break the continuity of non adjacent valid pairs
                t = ")" + t;
                continue;
            }
            else {
                -- cnt;
                t = "(" + t;
            }
        }
    }
    return {maxx, t, cnt};
}

int longestValidParentheses(string s) {
    
    tuple<int, string, int> temp = helper(s);
    
    // if # opening braces > # closing braces
    if(get<2>(temp) != 0)
        /*
         Reduce the problem to original problem
         where closing braces appear before opening braces
         */
        temp = helper(get<1>(temp));
    
    // return the new max
    if(get<0>(temp) % 2)
        return get<0>(temp) - 1;
    return get<0>(temp);
}

int main() {
    
    string s = ")(";
    cout << longestValidParentheses(s) << endl;
    
    s = "(()))())(";    // 4
    cout << longestValidParentheses(s) << endl;
    
    s = ")()())()()(";  // 4
    cout << longestValidParentheses(s) << endl;
    
    s = "(()";
    cout << longestValidParentheses(s) << endl;
    
    s = "())";
    cout << longestValidParentheses(s) << endl;
    
    s = "((()())";  // 6
    cout << longestValidParentheses(s) << endl;
    
    s = "";
    cout << longestValidParentheses(s) << endl;
    
    s = "()(()";      // 2
    cout << longestValidParentheses(s) << endl;
    
    s = "(()))()";      // 4
    cout << longestValidParentheses(s) << endl;
    
    s = "(((";
    cout << longestValidParentheses(s) << endl;
    
    s = ")))";
    cout << longestValidParentheses(s) << endl;
    return 0;
}

