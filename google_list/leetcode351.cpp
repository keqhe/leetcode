
class Solution {
public:
    //backtracking, see https://discuss.leetcode.com/topic/50052/20-lines-easy-understand-backtracking-with-explanations
    /*
    A B A
    B C B
    A B A
    */
    void backtracking(vector<vector<int>>&board, int x, int y, int step, int & total, int m, int n) {
        if (step > n)
            return;
        if (step >= m && step <= n)
            total ++;
        board[x][y] = step;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (board[i][j] != 0)
                    continue;
                //diag (corner)
                if (abs(x-i) == 2 && abs(y-j) == 2 && board[1][1] == 0)
                    continue;
                //same row
                if (x == i && abs(y-j) == 2 && board[x][1] == 0)
                    continue;
                //same column
                if (y == j && abs(x-i) == 2 && board[1][y] == 0)
                    continue;
                backtracking(board, i, j, step+1, total, m, n);
            }
        }
        board[x][y] = 0;
    }
    int numberOfPatterns(int m, int n) {
        if (m > n || n <= 0 || m > 9)
            return 0;
        vector<vector<int>> board(3, vector<int>(3, 0));
        int corner = 0;
        int second = 0;
        int center = 0;
        backtracking(board, 0, 0, 1, corner, m, n);
        backtracking(board, 0, 1, 1, second, m, n);
        backtracking(board, 1, 1, 1, center, m, n);
        
        return (corner+second)*4 + center;
    }
};
