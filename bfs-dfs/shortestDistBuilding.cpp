#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<limits>

using namespace std;

/*it is TLE in leetcode, i think the logic is correct though*/
struct pos {
    int x;
    int y;
    pos(int i, int j) {
        x = i;
        y = j;
    }
};
class Solution {
public:
    int bfs(vector<vector<int>> & grid, int total, int x, int y) {
        int matrix[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        queue<pair<struct pos, int>> q;
        struct pos p_tmp(x, y);
        q.push(make_pair(p_tmp, 1));
        int dist = 0;
	vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
	visited[x][y] = true;
        while (!q.empty()) {
            pair<struct pos, int> tmp = q.front();
	    q.pop();
            int r = tmp.first.x;
            int c = tmp.first.y;
            int level = tmp.second;//level
            for (auto u : matrix) {
                int i = r + u[0];
                int j = c + u[1];
                if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && visited[i][j] == false) {
		    visited[i][j] = true;
                    if (grid[i][j] == 1) {//reach a building
                        total --;
                        dist += level;
			//cout << total << endl;
                        if (total == 0)
                            return dist;
                    }
                    else if (grid[i][j] == 0) {
                        struct pos t(i, j);
                        q.push(make_pair(t, level+1));
                    }
                }
            }
        }
        if (total > 0) 
            return numeric_limits<int>::max();
        else
            return dist;
    }
    int shortestDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int dist = numeric_limits<int>::max();
        int total = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    total ++;
                }
            }
        }
        
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 0) {
                    dist = min(bfs(grid, total, i, j), dist);
                }
            }
        }
        if (dist == numeric_limits<int>::max())
            return -1;
        return dist;
    }
};

int main() {
	vector<vector<int>> input;
	vector<int> tmp = {1,0,2,0,1};
	input.push_back(tmp);
	tmp = {0,0,0,0,0};
	input.push_back(tmp);
	tmp = {0,0,1,0,0};
	input.push_back(tmp);
	class Solution sn;
	cout << sn.shortestDistance(input) << endl;
	cout << endl;
}
