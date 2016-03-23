
class Solution {
public:
    bool rule1(vector<vector<char>>& board) {
        bool ret = true;
        for (int i = 0; i < 9; i ++) {//i row
            unordered_map<char, bool> eachrow;
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    if (eachrow.find(board[i][j]) == eachrow.end())
                        eachrow[board[i][j]] = 1;
                    else
                        return false;
                }
            }
        }
        return ret;
    }
    
    bool rule2(vector<vector<char>>& board) {
        bool ret = true;
        for (int i = 0; i < 9; i ++) {//i colomn
            unordered_map<char, bool> eachcol;
            for (int j = 0; j < 9; j ++) {
                if (board[j][i] != '.') {
                    if (eachcol.find(board[j][i]) == eachcol.end())
                        eachcol[board[j][i]] = 1;
                    else
                        return false;
                }
            }
        }
        return ret;
    }
    
     bool rule3(vector<vector<char>>& board) {
        bool ret = true;
        for (int i = 0; i <= 6; ) {
            for (int j = 0; j <= 6; ) {
                unordered_map<char, bool> square;
                for (int m = 0; m <= 2; m ++) {
                    for (int n = 0; n <= 2; n ++ ) {
                        if (board[i + m][j + n] != '.') {
                            if (square.find(board[i + m][j + n]) == square.end())
                                square[board[i + m][j + n]] = 1;
                            else
                                return false;
                        }
                    }
                }
                j += 3;
            }
            i += 3;
        }
        return ret;
     }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        return rule1(board) && rule2(board) && rule3(board);
    }
};
