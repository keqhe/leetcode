
class Solution {
public:
    //reference about sudoku: http://bangbingsyb.blogspot.com/2014/11/leetcode-valid-sudoku-sudoku-solver.html
    //idea: 和N-Queen思路基本一样。对每个需要填充的位置枚举1-9，对每个枚举判断是否符合所在行、列、九宫格。如果符合则进行下一层递归。终止条件为填写完了整个棋盘。
    //ref2: https://leetcode.com/discuss/65517/c-clear-solution-using-dfs-beating-90%25-c-coder
    bool isValid (vector<vector<char>> & board, int i, int j) {//if we update board[i][j], still valid?
        int val = board[i][j] - '0';
        if (val > 9 || val < 1) 
            return false;
        //check row
        for (int k = 0; k < 9; k ++) {
            if ((board[i][k] ==  board[i][j]) && k != j)
                return false;
        }
        //check col
        for (int k = 0; k < 9; k ++) {
            if ((board[k][j] == board[i][j]) && k != i)
                return false;
        }
        //check block where [i][j] is located,e,g, [5][7]
        int block_row = i/3*3;
        int block_col = j/3*3;
        
        for (int p = block_row; p < block_row + 3; p ++) {
            for (int q = block_col; q < block_col + 3; q ++) {
                if ((board[p][q] == board[i][j]) && (p != i || q != j))
                    return false;
            }
        }
        //pass all the rules
        return true;
    }
    bool backtracking(vector<vector<char>>&board, int i, int j) {
        if (i == 9)
            return true;
        int nxt_i;
        int nxt_j;
        if (j == 8) {
            nxt_i = i+1;
            nxt_j = 0;
        }
        else {
            nxt_i = i;
            nxt_j = j + 1;
        }
        
        if (board[i][j] != '.') {
            return backtracking(board, nxt_i, nxt_j);
        }
        
        else if (board[i][j] == '.') {
            for (int k = 1; k <= 9; k ++) {//try to put "k" into [i][j]
                board[i][j] = k + '0';
                if (isValid(board, i, j) && backtracking(board, nxt_i, nxt_j))
                    return true;
            }
            //reset
            board[i][j] = '.';
            return false;//why we need it here?, otherwise, contine to grow in the wrong way..
        }
        
    }
    void solveSudoku(vector<vector<char>>& board) {
        if (board.size() < 9 || board[0].size() < 9)
            return;
        bool sol = backtracking(board, 0, 0);
    }
};
