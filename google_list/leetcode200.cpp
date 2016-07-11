
class Solution {
public:
    void dfs(vector<vector<char>>&grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1')
            return;
        grid[x][y] = '\0';
        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
    }
    void bfs(vector<vector<char>>&grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != '1')
            return;
        queue<pair<int, int>> q;
        int tmp[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        q.push(make_pair(x, y));
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int curr_x = curr.first;
            int curr_y = curr.second;
            grid[curr_x][curr_y] = '\0';
            for (auto p : tmp) {
                int x2 = curr_x + p[0];
                int y2 = curr_y + p[1];
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && grid[x2][y2] == '1') {
                    q.push(make_pair(x2, y2));
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for (int i = 0; i < m ; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    count ++;
                    dfs(grid, i, j);
                    //bfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
