
class Solution {
public:
    //1. get the total number of buildings
    //2. for each empty place, do a BFS. Record the distance to all reachable buildings. If all the buildings are reachable, calculate the sum.
    //3. If some sums exist, pick the smallest one, otherwise return -1.
    //the following code works, but has TLE because in one special test case, there are many more empty spaces (0) than buildings
    void bfs(vector<vector<int>>& grid, int x, int y, int & curr, int &reach) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int level = 0;
        q.push(make_pair(x, y));
        visited[x][y] = true;
        while (!q.empty()) {
            int size = q.size();
            level ++;
            for (int i = 0; i < size; i ++) {
                auto pos = q.front();
                q.pop();
                for (auto tmp : directions) {
                    int x2 = pos.first+tmp[0];
                    int y2 = pos.second+tmp[1];
                    if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && !visited[x2][y2]) {
                        visited[x2][y2] = true;
                        if (grid[x2][y2] == 1) {
                            reach ++;//reach another building
                            curr += level;
                        }
                        if (grid[x2][y2] == 0) {
                            q.push(make_pair(x2, y2));
                        }
                    }
                }
            }
        }
    }
    
    void bfs2(vector<vector<int>>& grid, int x, int y, vector<vector<int>> & dist, vector<vector<int>> &reach) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> directions = {{-1,0},{1,0},{0,-1},{0,1}};
        int level = 0;
        q.push(make_pair(x, y));
        visited[x][y] = true;
        while (!q.empty()) {
            int size = q.size();
            level ++;
            for (int i = 0; i < size; i ++) {
                auto pos = q.front();
                q.pop();
                for (auto tmp : directions) {
                    int x2 = pos.first+tmp[0];
                    int y2 = pos.second+tmp[1];
                    if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && grid[x2][y2] == 0 && !visited[x2][y2]) {
                        visited[x2][y2] = true;
                        dist[x2][y2] += level;
                        reach[x2][y2] ++;
                        q.push(make_pair(x2, y2));
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
        int total_buildings = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1)
                    total_buildings ++;
            }
        }
        vector<vector<int>> reach(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    bfs2(grid, i, j, distance, reach);
                }
            }
        }
        int min_distance = numeric_limits<int>::max();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 0) {
                    cout << reach[i][j] << endl;
                    if (reach[i][j] == total_buildings) {
                        min_distance = min(min_distance, distance[i][j]);
                    }
                }
            }
        }
        return min_distance == numeric_limits<int>::max() ? -1 : min_distance;
    }
};
