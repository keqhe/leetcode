
class Solution {
public:
    //dead 0
    //live 1
    //dead->dead 00
    //live->dead 01
    //dead->live 10
    //live->live 11
    int countLive(vector<vector<int>>& board, int x, int y) {
        int m = board.size();
        int n = board[0].size();
        int tmp[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}};
        int res = 0;
        for (auto t : tmp) {
            int x2 = x + t[0];
            int y2 = y + t[1];
            if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n) {
                if ( (board[x2][y2] & 1) == 1)
                    res ++;
            }
        }
        return res;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int cnt = countLive(board, i, j);
                cout << i << " " << j << " " << cnt<< endl;
                if (board[i][j] == 0) {
                    if (cnt == 3)
                        board[i][j] = 2;
                }
                else {
                    if (cnt < 2 || cnt > 3)
                        board[i][j] = 1;
                    else
                        board[i][j] = 3;
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
