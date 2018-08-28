/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
*/

class TicTacToe {
public:
    vector<int> row, col;
    int diag1, diag2, n;
    /** Initialize your data structure here. */
    TicTacToe(int n) : row(n), col(n), diag1(0), diag2(0), n(n) { }
    
    /** Player {player} makes a move at ({row}, {col}).
     @param row The row of the board.
     @param col The column of the board.
     @param player The player, can be either 1 or 2.
     @return The current winning condition, can be either:
     0: No one wins.
     1: Player 1 wins.
     2: Player 2 wins. */
    int move(int i, int j, int player) {
        if(player == 1) {
            ++row[i];
            ++col[j];
        }
        else {
            --row[i];
            --col[j];
        }
        if(i + j == n-1)
            player == 1 ? ++diag2 : --diag2;
        if(i == j)
            player == 1 ? ++diag1 : --diag1;
        if(abs(row[i]) == n || abs(col[j]) == n || abs(diag1) == n || abs(diag2) == n)
            return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
