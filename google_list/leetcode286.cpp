
class Solution {
public:
    //BFS
    //we can bfs from the empty room
    //or we can bfs from the gate
    //but BFS meets TLE
    
    //or we can use a visited 2D vector to mark whether we still need to visit
    void dfs(vector<vector<int>>& rooms, int x, int y, int depth) {
        int m = rooms.size();
        int n = rooms[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || rooms[x][y] < depth) 
            return; // no need to do DFS
        rooms[x][y] = depth;
        dfs(rooms, x-1, y, depth+1);
        dfs(rooms, x+1, y, depth+1);
        dfs(rooms, x, y-1, depth+1);
        dfs(rooms, x, y+1, depth+1);
    } 
    //actually this problem, we can also use DFS
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;
        int m = rooms.size();
        int n = rooms[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (rooms[i][j] == 0) {
                    dfs(rooms, i, j, 0);
                }
            }
        }
    }
};
