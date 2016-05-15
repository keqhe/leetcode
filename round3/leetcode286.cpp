
class Solution {
public:
    //bfs meets TLE (maybe need some memorization to reduce time complexity)
    //two bfs solution, from each empty room to a gate or from each gate all empty rooms
    void dfs_naive(vector<vector<int>>&rooms, int x, int y, int step, vector<vector<bool>>&used) {
        int m = rooms.size();
        int n = rooms[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] == -1 || used[x][y])
            return;
        used[x][y] = true;
        if (rooms[x][y] > step)
            rooms[x][y] = step;
        dfs_naive(rooms, x-1, y, step+1, used);
        dfs_naive(rooms, x+1, y, step+1, used);
        dfs_naive(rooms, x, y-1, step+1, used);
        dfs_naive(rooms, x, y+1, step+1, used);
        used[x][y] = false;
    }
    //think why even without used 2D vector, the following works
    void dfs(vector<vector<int>>&rooms, int x, int y, int step) {
        int m = rooms.size();
        int n = rooms[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] == -1)
            return;
        if (step == 0 || rooms[x][y] > step) {//this eliminate any unnecessary searches
            rooms[x][y] = step;
            dfs(rooms, x-1, y, step+1);
            dfs(rooms, x+1, y, step+1);
            dfs(rooms, x, y-1, step+1);
            dfs(rooms, x, y+1, step+1);
        }
    }
    
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;
        int m = rooms.size();
        int n = rooms[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (rooms[i][j] == 0) {//dfs from a gate
                    dfs(rooms, i, j, 0);
                }
            }
        }
    }
};
