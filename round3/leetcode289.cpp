
class Solution {
public:
    //encoding
    //0 dead
    //1 live
    //00->dead to dead
    //01->dead to live
    //10->live to dead
    //11->live to live
    
    //above encoding is not correct, think why?
    //[2nd bit, 1st bit] = [next state, current state]
    //[1 0] <----- [live, dead]
    //[1 1] <------[live, live]
    //[0 1] <------[dead, live]
    //[0 0] <------[dead, dead]
    int count(vector<vector<int>>& board, int x, int y) {
        int tmp[8][2] = {{-1,-1},{1,1}, {-1, 1},{1,-1},{-1, 0}, {1, 0}, {0, -1}, {0,1}};
        int m = board.size();
        int n = board[0].size();
        int cnt = 0;
        for (auto p : tmp) {
            int x2 = p[0] + x;
            int y2 = p[1] + y;
            if (x2 >= 0 && x2 < m &&  y2 >= 0 && y2 < n) {
                if (board[x2][y2] == 1 || board[x2][y2] == 3)
                    cnt ++;
            }
        }
        return cnt;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int live_cnt = count(board, i, j);
                if (board[i][j] == 0) {
                    if (live_cnt == 3)
                        board[i][j] = 2;
                }
                else if (board[i][j] == 1) {
                    if (live_cnt < 2)
                        board[i][j] = 1;
                    else if (live_cnt == 2 || live_cnt == 3)
                        board[i][j] = 3;
                    else if (live_cnt > 3)
                        board[i][j] = 1;
                }
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                board[i][j] = (board[i][j] >> 1);
            }
        }
    }
};
