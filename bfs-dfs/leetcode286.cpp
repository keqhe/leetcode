#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

class Solution {
public:
    //do not know why DFS is so fast...
    void dfs(vector<vector<int>> & rooms, int i, int j, int depth) {
        int m = rooms.size();
        int n = rooms[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        if (rooms[i][j] == -1)
            return;
        if (depth == 0 || rooms[i][j] > depth) {//depth == 0 kicks dfs off
            rooms[i][j] = depth;
            dfs(rooms, i+1, j, depth+1);
            dfs(rooms, i-1, j, depth+1);
            dfs(rooms, i, j-1, depth+1);
            dfs(rooms, i, j+1, depth+1);
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;
        for (int i = 0; i < rooms.size(); i ++) {
            for (int j = 0; j < rooms[0].size(); j ++) {
                if (rooms[i][j] == 0)
                    dfs(rooms, i, j, 0);
            }
        }
    }
    
    /*second version, still TEL, this article is informative: https://leetcode.com/discuss/82264/benchmarks-of-dfs-and-bfs
    //bfs, from each gate to all empty rooms, still TLE
    void bfs(vector<vector<int>>&rooms, int row, int col) {
        queue<pair<int, int>> q;
        int m = rooms.size();
        int n = rooms[0].size();
        vector<vector<bool>> used(m, vector<bool>(n, false));
        int temp[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        q.push(make_pair(row, col));
        while(!q.empty()) {
            pair<int,int> curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            used[x][y] = true;
            for (auto p : temp) {
                int x2 = x + p[0];
                int y2 = y + p[1];
                //rooms[x2][y2] > rooms[x][y]+1 condition is important 
                if (x2 >= 0 && x2 < m && y2 >= 0 && y2 < n && !used[x2][y2] && rooms[x2][y2] > rooms[x][y]+ 1) {
                    rooms[x2][y2] = rooms[x][y] + 1;
                    q.push(make_pair(x2, y2));
                }
            }
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;
        for (int i = 0; i < rooms.size(); i ++) {
            for (int j = 0; j < rooms[0].size(); j ++) {
                if (rooms[i][j] == 0)
                    bfs(rooms, i, j);
            }
        }
    }*/
    //TLE version, idea is bfs, from each empty to a gate, but failed for a tough test case
    /*
    void bfs(vector<vector<int>>&rooms, int row, int col) {
        queue<pair<int, int>> q;
        int level = 0;
        q.push(make_pair(row, col));
        vector<vector<bool>> used(rooms.size(), vector<bool>(rooms[0].size(), false));
        int help[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        while (!q.empty()) {
            int count = q.size();
            for (int k = 0; k < count; k ++) {
                pair<int, int> curr = q.front();
                q.pop();
                int x = curr.first; 
                int y = curr.second;
                used[x][y] = true;
                if (rooms[x][y] == 0) {
                    rooms[row][col] = level;
                    return;
                }
                else {
                    for (auto p : help) {
                        int x2 = x + p[0];
                        int y2 = y + p[1];
                        if (x2 >= 0 && x2 < rooms.size() && y2 >= 0 && y2 < rooms[0].size() && !used[x2][y2] && rooms[x2][y2] != -1) {
                            q.push(make_pair(x2, y2));
                        }
                    }
                }
            }
            level ++;
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;
        for (int i = 0; i < rooms.size(); i ++) {
            for (int j = 0; j < rooms[0].size(); j ++) {
                if (rooms[i][j] == numeric_limits<int>::max())
                    bfs(rooms, i, j);
            }
        }
    }*/
};


int main() {
	class Solution sn;	
	return 0;
}
