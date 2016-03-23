
class Solution {
public:
    //idea: DFS or BFS
    //DFS: https://leetcode.com/discuss/69602/my-easy-to-understand-java-solution
    //ref: sourrounded regions
    //https://leetcode.com/discuss/31010/dfs-and-bfs-in-c
    int cover[4][2] = {{-1,0},{0,-1}, {1,0}, {0,1}};
    void bfs(vector<vector<char>>& grid, int i, int j) {
    
        grid[i][j] = '0';
        queue<pair<int,int>> q;
        q.push(make_pair(i,j));
        while (!q.empty()) {
            pair<int,int> tmp = q.front();
            q.pop();
            for (auto &cord : cover) {
                int x = tmp.first + cord[0];
                int y = tmp.second + cord[1];
                if (x < 0 || y < 0 || x > grid.size() - 1 || y > grid[0].size() - 1)
                    continue;
                if (grid[x][y] == '1') {
                    grid[x][y] = '0';
                    q.push(make_pair(x,y));
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()|| grid[0].empty())
            return 0;
        int total = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == '1') {
                    total += 1;
                    bfs(grid, i, j);
                }
            }
        }
        return total;
    }
};
