class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        int xCount = 0, oCount = 0;

        // Count occurrences of 'X' and 'O'
        for (const auto& row : board) {
            for (char c : row) {
                if (c == 'X') xCount++;
                else if (c == 'O') oCount++;
            }
        }

        // Rule 1: X goes first, so X's count should be equal to or one more than O's count
        if (xCount != oCount && xCount != oCount + 1) return false;

        // Check if there's a winning line for 'X' or 'O'
        bool xWins = checkWin(board, 'X');
        bool oWins = checkWin(board, 'O');

        // Rule 2: If 'X' wins, there must be exactly one more 'X' than 'O'
        if (xWins && xCount != oCount + 1) return false;

        // Rule 3: If 'O' wins, there must be exactly as many 'X's as 'O's
        if (oWins && xCount != oCount) return false;

        // Rule 4: Both players cannot have won simultaneously
        if (xWins && oWins) return false;

        return true;
    }

private:
    bool checkWin(vector<string>& board, char player) {
        // Check rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
                (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
            (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
            return true;
        }
        return false;
    }
};
