
class Solution {
public:
    void dfs(vector<vector<int>>& rooms, int x, int y, int depth) {
        int m = rooms.size();
        int n = rooms[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] == -1)
            return;
        if (depth == 0 || rooms[x][y] > depth) {
            rooms[x][y] = depth;
            dfs(rooms, x+1, y, depth+1);
            dfs(rooms, x-1, y, depth+1);
            dfs(rooms, x, y+1, depth+1);
            dfs(rooms, x, y-1, depth+1);
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
