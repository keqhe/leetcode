
class Solution {
public:
    //check row
    bool checkRow(vector<vector<char>>& board, int r) {
        vector<bool> used(10, false);//0 to 9
        for (int j = 0; j < 9; j ++) {
            if (board[r][j] == '.')
                continue;
            int curr = board[r][j] - '0';
            if (used[curr])
                return false;
            used[curr] = true;
        }
        return true;
    }
    //check column
    bool checkCol(vector<vector<char>>& board, int c) {
        vector<bool> used(10, false);//0 to 9
        for (int i = 0; i < 9; i ++) {
            if (board[i][c] == '.')
                continue;
            int curr = board[i][c] - '0';
            if (used[curr])
                return false;
            used[curr] = true;
        }
        return true;
    }
    //check blocks
    bool checkBlock(vector<vector<char>>& board) {
        for (int c = 0; c <= 6; c += 3) {//0 3 6
            for (int r = 0; r <= 6; r += 3) {//0 3 6
                vector<bool> used(10, false);//0 to 9
                for (int i = r; i < r+3; i ++) {
                    for (int j = c; j < c+3; j ++) {
                        if (board[i][j] == '.')
                            continue;
                        int curr = board[i][j] - '0';
                        if (used[curr])
                            return false;
                        used[curr] = true;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())
            return false;
        for (int i = 0; i < 9; i ++) {
            bool row = checkRow(board, i);
            if (!row)
                return false;
        }
        
        for (int j = 0; j < 9; j ++) {
            bool col = checkCol(board, j);
            if (!col)
                return false;
        }
        
        if (!checkBlock(board))
            return false;
            
        return true;
    }
};
