/*
 You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
 
 Write a function to compute all possible states of the string after one valid move.
 
 Example:
 
     Input: s = "++++"
     Output:
     [
     "--++",
     "+--+",
     "++--"
     ]
 
 Note: If there is no valid move, return an empty list [].
 */

vector<string> generatePossibleNextMoves(string s) {
    int n = s.size(), i = 0;
    vector<string> ans;
    while(i < n-1) {
        if(s[i] == '+' && s[i+1] == '+') {
            string temp = s;
            temp[i] = temp[i+1] = '-';
            ans.push_back(temp);
        }
        ++i;
    }
    return ans;
}
