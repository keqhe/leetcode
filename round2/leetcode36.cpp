
class Solution {
public:
    bool checkRow (vector<vector<char>> & board) {
        for (int i = 0; i < 9; i ++) {
            vector<bool> check (9, false);
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]-'0'] == false)
                        check[board[i][j]-'0'] = true;
                    else    
                        return false;
                }
            }
        }
        return true;
    }
    
    bool checkCol(vector<vector<char>> & board) {
        for (int j = 0; j < 9; j ++) {
            vector<bool> check (9, false);
            for (int i = 0; i < 9; i ++) {
                if (board[i][j] != '.') {
                    if (check[board[i][j]-'0'] == false)
                        check[board[i][j]-'0'] = true;
                    else    
                        return false;
                }
            }
        }
        return true;
    }
    
    bool checkBlock(vector<vector<char>> & board) {
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> check(9, false);
                for (int k = 0; k < 9; k ++) {
                    int x = i + k / 3;
                    int y = j + k % 3;
                    if (board[x][y] != '.') {
                        if (check[board[x][y]-'0'] == false)
                            check[board[x][y]-'0'] = true;
                        else
                            return false;
                    }
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty())  
            return false;
        
        if (!checkRow(board))
            return false;
        if (!checkCol(board))
            return false;
        if (!checkBlock(board))
            return false;
        return true;
    }
};
