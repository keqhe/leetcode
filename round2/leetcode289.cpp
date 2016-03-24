
class Solution {
public:
    //first thought, encoding as below..
    //case 1: fewer than 2 neighbors are live, turn into dead, encoded as 2 
    //case 2: 2 and 3 neighbors are alive, reborn, encoded as 4
    //case 3: 3 neighbors are alive, keep born, encoded as 5
    //case 4: > 3 neighbors are alive, to dead, encoded as 3
    //but see the following ref which is much better
    //ref: https://leetcode.com/discuss/68352/easiest-java-solution-with-explanation
    //[2nd bit, 1st bit] = [next state, current state]
    //[1 0] <----- [live, dead]
    //[1 1] <------[live, live]
    //[0 1] <------[dead, live]
    //[0 0] <------[dead, dead]
    
    // [[1 1],
    //  [1 0]]
    int countLive(vector<vector<int>>&board, int x, int y) {
        int temp[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, 1}, {1, -1}, {-1, -1}, {1, 1}};
        int count = 0;
        for (auto u : temp) {
            int x2 = x + u[0];
            int y2 = y + u[1];
            
            if (x2 >= 0 && x2 < board.size() && y2 >= 0 && y2 < board[0].size()) {
                cout << "debug3:" <<  x2 << " " << y2 << endl;
                if ((board[x2][y2] & 1) == 1)
                    count ++;
            }
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty() || board[0].empty())
            return;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                int cnt = countLive(board, i, j);
                cout << cnt << endl;
                if (board[i][j] == 0) {//current state is dead
                    if (cnt == 3)
                        board[i][j] = 2;
                }
                else if (board[i][j] == 1) {
                    if (cnt >= 2 && cnt <= 3)
                        board[i][j] = 3;//[11]
                }
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                board[i][j] >>= 1;
            }
        }
    }
};
