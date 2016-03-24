
class Solution {
public:
    //grid, orginal board; 
    //"distance" records the sum of shortest paths from point [x,y] to all reachable buildings 
    //total denotes how many buildings are reachable from point [x,y]
    /*the version is logically correct, but TLE for a tough test case which has a lot of 0s but much fewer 1s....
    void bfs(vector<vector<int>> & grid, int x, int y, int & total, int & distance) {
        int m = grid.size();
        int n = grid[0].size();
        int matrix[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        int level = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        visited[x][y] = true;
        //cout << "x and y are: " << x  << " " << y << endl;
        while (!q.empty()) {
            
            int count = q.size();
            for (int k = 0; k < count; k ++) {
                pair<int, int> curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;
                
                
                for (auto u : matrix) {
                    int i = r + u[0];
                    int j = c + u[1];
                
                    if (i >= 0 && i < m && j >= 0 && j < n && !visited[i][j]) {
                        visited[i][j] = true;//building, and empty land both needs to be set as visited
                        //otherwise, duplicating counts...
                        if (grid[i][j] == 1) {//reach a building
                            distance += level+1;
                            total ++;
                        }
                        else if (grid[i][j] == 0) {
                            q.push(make_pair(i,j));
                        }
                    }
                }
            }
            level ++;
        }
        //cout << "LEVEL is :" << level << endl;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        int dist = numeric_limits<int>::max();
        int totalBuildings = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    totalBuildings ++;
                }
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 0) {
                    int total = 0;
                    int distance = 0;
                    bfs(grid, i, j, total, distance);
                    //cout << "point " << i << " " << j << ": " << total << " " << distance << endl;
                    if (total == totalBuildings) {
                        dist = min(dist, distance);
                    }
                }
            }
        }
        
        return dist;
    }*/
    void bfs(vector<vector<int>>&grid, int row, int col, vector<vector<int>>&reach, vector<vector<int>> & distances) {
        int m = grid.size();
        int n = grid[0].size();
        
        queue<pair<int,int>> q;
        q.push(make_pair(row, col));
        int level = 0;
        int temp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        while (!q.empty()) {
            int count = q.size();
            for (int k = 0; k < count; k ++) {
                pair<int,int> curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                for (auto p : temp) {
                    int x2 = x + p[0];
                    int y2 = y + p[1];
                    if (x2>=0 && x2<m && y2>=0 && y2<n && !visited[x2][y2] && grid[x2][y2]==0) {
                        visited[x2][y2] = true;
                        reach[x2][y2] ++;//from point (x2,y2), one more building is reachable
                        distances[x2][y2] += level+1;
                        q.push(make_pair(x2,y2));
                    }
                }
            }
            level ++;
        }
    }
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        int dist = numeric_limits<int>::max();
        int totalBuildings = 0;
        vector<vector<int>> reach(m, vector<int>(n, 0));//how many buildings each empty land can reach
        vector<vector<int>> distances(m, vector<int>(n, 0));//the sum of shortest distances from each empty land to all the reachable buildings
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    totalBuildings ++;
                }
            }
        }
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    bfs(grid, i, j, reach, distances);
                }
            }
        }
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (reach[i][j] == totalBuildings) {
                    dist = min(dist, distances[i][j]);
                }
            }
        }
        return dist == numeric_limits<int>::max() ? -1 : dist;
    }
};
