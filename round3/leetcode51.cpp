
class Solution {
public:
    //if we try to put a 'Q' at position [x][y], is that valid?
    bool check(vector<string> & board, int x, int y, int n) {
        for (int i = 0; i <= x-1; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'Q' && j == y || //in the same column
                    board[i][j] == 'Q' && abs(x-i) == abs(y-j)) //diag
                    return false;
            }
        }
        return true;//valid
    }
    void backtracking(vector<string> & board, int n, int row, vector<vector<string>> & res) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int j = 0; j < n; j ++) {
            if (check(board, row, j, n)) {
                board[row][j] = 'Q';
                backtracking(board, n, row+1, res);
                board[row][j] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n == 0)
            return res;
        vector<string> board(n, string(n, '.'));
        backtracking(board, n, 0, res);
        return res;
    }
};
