class Solution {
public:
    //the naive solution (using bfs) is to bfs starting from each empty land and find a place that gives the optimal (smallest) sum, but this method has TLE issue
    
    //bfs starts from each building (1)
    void bfs(vector<vector<int>>& grid, int x, int y, vector<vector<int>>&reach, vector<vector<int>>& dist) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 1)
            return;
        int direct[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        int level = 0;
        while (!q.empty()) {
            level ++;
            int size = q.size();
            for (int i = 0; i < size; i ++) {
                pair<int, int> curr = q.front();
                q.pop();
                int _x = curr.first;
                int _y = curr.second;
                for (auto t : direct) {
                    int x2 = _x + t[0];
                    int y2 = _y + t[1];
                    if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && grid[x2][y2] == 0 && !visited[x2][y2]) {
                        reach[x2][y2] ++;
                        dist[x2][y2] += level;
                        
                        q.push(make_pair(x2, y2));
                        visited[x2][y2] = true;
                    }
                }
            }
        }
    }
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return -1;
        int m = grid.size();
        int n = grid[0].size();
        //reach: from empty land [i][j], how many buildings can be reached
        vector<vector<int>> reach(m, vector<int>(n, 0));
        //sum_dist: from each empty land [i][j], what's the total steps to reach all buildings (if possible)
        vector<vector<int>> sum_dist(m, vector<int>(n, 0));
        
        int totalBuildings = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1)
                    totalBuildings ++;
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1)
                    bfs(grid, i, j, reach, sum_dist);
            }
        }
        int minDist = numeric_limits<int>::max();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 0) {
                    if (reach[i][j] == totalBuildings) {
                        minDist = min(minDist, sum_dist[i][j]);
                    }
                }
            }
        }
        return minDist == numeric_limits<int>::max() ? -1 : minDist;
    }
};
