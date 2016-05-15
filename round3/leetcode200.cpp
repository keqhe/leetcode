
class Solution {
public:
    //bfs or dfs 
    void dfs(vector<vector<char>> & grid, int x, int y) {
        int m = grid.size();
        int n = grid[0].size();
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == '0')
            return;
        grid[x][y] = '0';//make as visited
        dfs(grid, x-1, y);
        dfs(grid, x+1, y);
        dfs(grid, x, y-1);
        dfs(grid, x, y+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    count ++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }
};
