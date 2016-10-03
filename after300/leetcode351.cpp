
class Solution {
public:
    void dfs(vector<vector<int>>&board, int x, int y, int m, int n, int length, int& total) {
        length ++;
        if (length > n)
            return;
        if (length >= m && length <= n)
            total ++;
        board[x][y] = -1;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (board[i][j] == 1) {//not used
                    if (i == x && abs(y-j) == 2) {
                       if (board[i][1] == -1) {
                           dfs(board, i, j, m, n, length, total);
                       } 
                    }
                    else if (j == y && abs(x-i) == 2) {
                       if (board[1][j] == -1) {
                           dfs(board, i, j, m, n, length, total);
                       } 
                    }
                    else if (abs(i-x) == 2 && abs(j-y) == 2) {
                       if (board[1][1] == -1) {
                           dfs(board, i, j, m, n, length, total);
                       } 
                    }
                    else {
                        dfs(board, i, j, m, n, length, total);
                    }
                }
            }
        }
        board[x][y] = 1;
    }
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> board(3, vector<int>(3, 1));
        int part1 = 0;
        int part2 = 0;
        int part3 = 0;
        dfs(board, 0, 0, m, n, 0, part1);
        dfs(board, 0, 1, m, n, 0, part2);
        dfs(board, 1, 1, m, n, 0, part3);
        return 4*part1 + 4*part2 + part3;
    }
};
