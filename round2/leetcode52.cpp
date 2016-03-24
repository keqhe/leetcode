
class Solution {
public:
    bool check(int n, vector<string> path, int row, int col) {
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < n; j ++) {
                if (path[i][j] == 'Q') {
                    if (col == j)
                        return false;
                    if (row-i == abs(j-col))
                        return false;
                }
            }
        }
        return true;
    }
    //both the two are okay
    //void backtracking(int n, vector<string> & path, int row, int & res) {
    void backtracking(int n, vector<string>  path, int row, int & res) {
        if (n == row) {
            res ++;
            return;
        }
        for (int j = 0; j < n; j ++) {
            if (check(n, path, row, j)) {
                string tmp(n, '.');
                tmp[j] = 'Q';
                path.push_back(tmp);
                backtracking(n, path, row+1, res);
                path.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        vector<string> path;
        int count = 0;
        backtracking(n, path, 0, count);
        return count;
    }
};
