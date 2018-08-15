/*You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
 
 Write a function to determine if the starting player can guarantee a win.
 
 Example:
     Input: s = "++++"
     Output: true
 Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
 
 Follow up:
 Derive your algorithm's runtime complexity.
 */

class Solution {
public:
    unordered_map<string, bool> dp;
    int n;
    string S;
    
    bool helper() {
        if(dp.find(S) != dp.end())  return dp[S];
        for(int i = 0; i < n-1; ++i) {
            if(S[i] == '+' && S[i+1] == '+') {
                S[i] = '-'; S[i+1] = '-';
                // If there exists a case where B can't win, A wins
                if(!helper())  {
                    S[i] = '+'; S[i+1] = '+';
                    dp[S] = true;
                    return true;
                }
                S[i] = '+'; S[i+1] = '+';
            }
        }
        // B always won, A can never win
        dp[S] = false;
        return false;
    }
    bool canWin(string A) {
        S = A;
        n = A.size();
        return helper();
    }
};

// ------------------------------------------------------------------
bool helper(string &s, int &n) {
    
    for(int i = 0; i < n-1; ++i) {
        if(s[i] == '+' && s[i+1] == '+') {
            // current made atleast one move
            s[i] = '-'; s[i+1] = '-';
            // If B wins
            if(!helper(s, n))  {
                s[i] = '+'; s[i+1] = '+';
                return true;
            }
            s[i] = '+'; s[i+1] = '+';
        }
    }
    // B never won, return true
    return false;
}
bool canWin(string s) {
    int n = s.size();
    return helper(s, n);
}
