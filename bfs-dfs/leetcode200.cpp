#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    //dfs
    void dfs(vector<vector<char>> & grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (grid[i][j] != '1')
            return;
        grid[i][j] = '\0';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
        //grid[i][j] = '1';
    }
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    cnt ++;
                    dfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
    
    //bfs, TLE
    void bfs(vector<vector<char>> & grid, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>> q;
        q.push(make_pair(i, j));
        int direction[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            grid[x][y] = '\0';//think this as "used" or "visited" array
            for (auto p : direction) {
                int x2 = x + p[0];
                int y2 = y + p[1];
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && grid[x2][y2] == '1') {
                    q.push(make_pair(x2, y2));
                }
            }
        }
    }
    int numIslands_bfs(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == '1') {
                    cnt ++;
                    bfs(grid, i, j);
                }
            }
        }
        return cnt;
    }
};

int main() {
	class Solution sn;
	return 0;
}
