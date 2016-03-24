
class Solution {
public:
    bool check(vector<vector<char>> &board, int row, int col, char val) {
        for (int j = 0; j < 9; j ++) {
            if (board[row][j] == val && j != col)
                return false;
        }
        //cout << "debug1" << endl;
        for (int i = 0; i < 9; i ++) {
            if (board[i][col] == val && i != row)
                return false;
        }
        //cout << "debug2" << endl;
        int b_row = (row / 3)*3;
        int b_col = (col / 3)*3;
        for (int i = b_row; i < b_row+3; i ++) {
            for (int j = b_col; j < b_col+3; j ++) {
                if (board[i][j] == val && (i != row || j != col))
                    return false;
            }
        }
        //cout << "debug3" << endl;
        return true;
    }
    bool backtracking(vector<vector<char>>& board, int row, int col) {
        if (col == 9) {
            col = 0;
            row ++;
        }
        //cout << row << " " << col << endl;
        if (row == board.size())
            return true;
        
        if (board[row][col] == '.') {
            for (int c = '1'; c <= '9'; c ++) {
                if (check(board, row, col, c)) {
                    board[row][col] = c;
                    if (backtracking(board, row, col+1))
                        return true;
                    board[row][col] = '.';
                }
            }
        }
        else {
            //the following two methods, either is fine
            if (backtracking(board, row, col+1))
                return true;
            
            //return backtracking(board, row, col+1);
        }
        
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool res = backtracking(board, 0, 0);
    }
};
