
class Solution {
public:
    //reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-n-queens-i-ii.html
    //ref2: https://leetcode.com/discuss/67227/concise-java-solution-based-on-dfs
    //grow the solution row by row, check col and diag
    bool isValid(vector<int> & usedCol, int i, int j) {//at board[i][j], if we put a queue, still valid?
        for (int k = 0; k < usedCol.size(); k ++) {
            if (usedCol[k] == j || (i - k) == abs(j - usedCol[k]))
                return false;
        }
        return true;
    }
    void backtracking(int size, int row, vector<int> & usedCol, vector<string> & cur_row, vector<vector<string>> & sol) {//size is grid size
        if (row == size) {
            sol.push_back(cur_row);
            return;
        }
        
        for (int j = 0; j < size; j ++) {
            if (isValid(usedCol, row, j)) {
                string tmp (size, '.');
                tmp[j] = 'Q';
                cur_row.push_back(tmp);
                usedCol.push_back(j);
                backtracking(size, row+1, usedCol, cur_row, sol);
                cur_row.pop_back();
                usedCol.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> usedCol;
        vector<string> cur_row;
        vector<vector<string>> res;
        backtracking(n, 0, usedCol, cur_row, res);
        return res;
    }
};
