/*
 Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses
 */

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void helper(vector<string> &ans, string current, int open, int close) {
    if(open > close) {
        return;
    }

    if((open==0) && (closed == 0)) {
        ans.push_back(current);
        return;
    }
    
    if (open > 0) {
        helper(ans, current + "(", open - 1, close);
    }
    
    if(closed > 0) {
        helper(ans, current + ")" , open, close - 1);
    }
}

vector<string> generateParenthesis(int n) {
    
    if(!n)
        return {};
    
    if(n == 1)
        return {"()"};
    
    vector<string> ans;
    helper(ans, "", n, n);
    
    return ans;
}


void find_print(int n) {
    vector<string> temp = generateParenthesis(n);
    cout << n << endl;
    for(int i = 0; i < temp.size(); ++i)
        cout << temp[i] << endl;
    cout << endl;
}

int main() {
    
    for(int i = 0; i < 5; ++i)
        find_print(i);
    
    return 0;
}

/* Bad approach */
vector<string> generateParenthesis1(int n) {
    
    if(!n)
        return {};
    
    if(n == 1)
        return {"()"};
    
    set<string> thisSet;
    vector<string> prev = generateParenthesis1(n - 1);
    
    for(string elem : prev) {
        for(int j = 0; j < elem.size(); ++j) {
            string temp = elem.substr(0, j) + "()" + elem.substr(j);
            if(thisSet.find(temp) == thisSet.end())
                thisSet.insert(temp);
        }
    }
    vector<string> ans;
    for(string elem : thisSet)
        ans.push_back(elem);
    
    return ans;
}
