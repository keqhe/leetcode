
class Solution {
public:
    //man, this is DFS: haha, nice solution though, https://leetcode.com/discuss/73686/concise-java-solution-bfs-7ms
    //
    void bfs(vector<vector<int>>& rooms, int i, int j) {
        if (i < 0 || j < 0 || i >= rooms.size() || j >= rooms[0].size())
            return;
        int matrix[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
        queue<pair<pair<int,int>, int>> q;
        q.push(make_pair(make_pair(i, j), 0));
        while (!q.empty()) {
            pair<pair<int,int>,int> tmp = q.front();
            q.pop();
            int x = tmp.first.first;
            int y = tmp.first.second;
            int level = tmp.second;
            for (int i = 0; i < 4; i ++) {
                int newx = x + matrix[i][0];
                int newy = y + matrix[i][1];
                if (newx >= 0 && newx < rooms.size() && newy >= 0 && newy < rooms[0].size()) {
                    if (rooms[newx][newy] > level+1) {
                        rooms[newx][newy] = level+1;
                        q.push(make_pair(make_pair(newx, newy), level+1));
                    }
                }
            }
        }
    }
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty() || rooms[0].empty())
            return;
        for (int i = 0; i < rooms.size(); i ++) {
            for (int j = 0; j < rooms[0].size(); j ++) {
                if (rooms[i][j] == 0) {
                    bfs(rooms, i, j);
                }
            }
        }
    }
};
