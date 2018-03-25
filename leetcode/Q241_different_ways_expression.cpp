/*
 Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int evaluate(int a, int b, char op) {
    if(op == '+')
        return a + b;
    if(op == '-')
        return a - b;
    if(op == '*')
        return a*b;
    
    return 0;   // Xcode compulsion
}

vector<int> helper(string s, int start, int end, vector<vector<vector<int> > > &dp) {
    if(dp[start][end].size() == 0) {
        int i = start;
        string temp = "";
        while(i <= end && isdigit(s[i])) {
            temp += s[i];
            ++ i;
        }

        if(i == end + 1)
            dp[start][end].push_back(stoi(temp));
        else {
            vector<int> leftPossile, rightPossible;
            for(int i = start; i <= end; ++i) {
                if(s[i] == '*' || s[i] == '+' || s[i] == '-') {
                    leftPossile = helper(s, start, i - 1, dp);
                    rightPossible = helper(s, i + 1, end, dp);
                    
                    for(int left : leftPossile) {
                        for(int right : rightPossible) {
                            dp[start][end].push_back(evaluate(left, right, s[i]));
                        }
                    }
                }
            }
        }
    }
    return dp[start][end];
}

vector<int> diffWaysToCompute(string input) {
    int n = input.size();
    vector<vector<int> > temp1(n, vector<int> (0));
    vector<vector<vector<int> > > dp(n, temp1);
 
    return helper(input, 0, n - 1, dp);
}

void find_print(string &s) {
    vector<int> temp = diffWaysToCompute(s);
    for(int i : temp)
        cout << i << "\t";
    cout << endl;
}


int main() {
    string s = "2-1-1";
    find_print(s);
    
    s = "2*3-4*5";
    find_print(s);

    return 0;
}
