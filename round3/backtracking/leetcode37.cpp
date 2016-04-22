
class Solution {
public:
    bool check(vector<vector<char>>&board, int x, int y, int val) {
        //check row
        for (int j = 0; j < 9; j ++) {
            if (board[x][j] != '.' && board[x][j] == val+'0')
                return false;
        }
        //check column
        for (int i = 0; i < 9; i ++) {
            if (board[i][y] != '.' && board[i][y] == val+'0')
                return false;
        }
        int a = x/3;
        int b = y/3;
        
        for (int i = a*3; i < a*3+3; i ++) {
            for (int j = b*3; j < b*3+3; j ++) {
                if (board[i][j] != '.' && board[i][j] == val+'0') {
                    return false;
                }
            }
        }
        return true;
    }
    bool backtracking(vector<vector<char>>&board, int r, int c) {
        if (c == 9) {
            r ++;
            c = 0;
        }
        if (r == board.size())
            return true;//a valid fill-up
        if (r >= 9 || c >= 9)
            cout << "WARING..." << r << " " << c << endl;
        if (board[r][c] == '.') {
            for (int i = 1; i <= 9; i ++) {
                if (check(board, r, c, i)) {
                    board[r][c] = i+'0';
                    if (backtracking(board, r, c+1))
                        return true;
                    board[r][c] = '.';
                }
            }
        }
        else {
            if (backtracking(board, r, c+1))
                return true;
        }
        return false;//false is returned last, this might be why finally we get a correct fill-up
    }
    void solveSudoku(vector<vector<char>>& board) {
        //bool test = check(board, 0, 1, 6);
        //cout << test << endl;
        bool res = backtracking(board, 0, 0);
    }
};
