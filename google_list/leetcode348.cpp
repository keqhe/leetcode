
class TicTacToe {
public:
    vector<int> win_row;
    vector<int> win_col;
    int diag = 0;
    int anti_diag = 0;
    int size = 0;
    bool won = false;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        win_row.resize(n);
        win_col.resize(n);
        diag = 0;
        anti_diag = 0;
        size = n;
        won = false;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if (won)
            return 0;
        int tmp = player == 1 ? 1 : -1;
        win_row[row] += tmp;
        win_col[col] += tmp;
        if (row == col)
            diag += tmp;
        if (row + col == size-1)
            anti_diag += tmp;
        if (win_row[row] == size || win_row[row] == -size ||
            win_col[col] == size || win_col[col] == -size ||
            diag == size || diag == -size ||
            anti_diag == size || anti_diag == -size) {
                won = true;
                return player;
            }
        else
            return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
