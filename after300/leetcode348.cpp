
class TicTacToe {
public:
    int size;
    vector<int> rows;
    vector<int> cols;
    int diag;
    int anti_diag;
    int winner;
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        size = n;
        rows.resize(n);
        cols.resize(n);
        diag = 0;
        anti_diag = 0;
        winner = 0;
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
        if (winner > 0)
            return winner;
        int p = player == 1 ? 1 : -1;
        rows[row] += p;
        cols[col] += p;
        if (row == col)
            diag += p;
        if (row + col == size - 1)
            anti_diag += p;
        if (rows[row] == size || rows[row] == -size ||
            cols[col] == size || cols[col] == -size ||
            diag == size || diag == -size || anti_diag == size ||
            anti_diag == -size) {
                winner = player;
                return winner;
            }
        return winner;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
