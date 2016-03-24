
class Solution {
public:
    bool check(vector<string> path, int row, int n, int col) {
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < n; j ++) {
                if (path[i][j] == 'Q') {
                    if (j == col)
                        return false;
                    if (row - i == abs(col - j))
                        return false;
                }
            }
        }
        return true;
    }
    void backtracking (int n, int row, vector<string> &path, vector<vector<string>> & res) {
        if (row == n) {
            res.push_back(path);
            return;
        }
        
        for (int j = 0; j < n; j ++) {
            if (check(path, row, n, j)) {
                string tmp (n, '.');
                tmp[j] = 'Q';
                path.push_back(tmp);
                backtracking(n, row+1, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> path;
        vector<vector<string>> res;
        backtracking(n, 0, path, res);
        return res;
    }
};
