
class Solution {
public:
    bool check(vector<string>&board, int x, int y, int n) {
        for (int i = 0; i <= x-1; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'Q' && j == y ||
                    board[i][j] == 'Q' && abs(x-i) == abs(y-j))
                        return false;
            }
        }
        return true;
    }
    void backtracking(vector<string>&board, int n,  int row, int &total) {
        if (row == n) {
            total ++;
            return;
        }
        for (int j = 0; j < n; j ++) {
            if (check(board, row, j, n)) {
                board[row][j] = 'Q';
                backtracking(board, n, row+1, total);
                board[row][j] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        if (n == 0)
            return 0;
        vector<string> board(n, string(n, '.'));
        int total = 0;
        backtracking(board, n, 0, total);
        return total;
    }
};
