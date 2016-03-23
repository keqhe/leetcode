
class Solution {
public:
    //encode, remember state (previous)
    //dead -> dead : 0
    //live -> live : 1
    //live -> dead : 2
    //dead -> live : 3
    //if it is 1 || 2, it means, it was live, but need to be changed to dead
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int cnt = 0;
                for (int dx = -1; dx <= 1; dx ++) {
                    for (int dy = -1; dy <= 1; dy ++) {
                        if (dx == 0 && dy == 0)
                            continue;
                        int x = i + dx;
                        int y = j + dy;
                        if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1|| board[x][y] == 2))
                            cnt ++;
                    }
                }
                //cout << cnt << endl;
                if (board[i][j] == 1 && (cnt < 2 || cnt > 3))
                    board[i][j] = 2;
                else if (board[i][j] == 0 && cnt == 3)
                    board[i][j] = 3;
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                board[i][j] %= 2; //note it is % not /
            }
        }
    }
};
