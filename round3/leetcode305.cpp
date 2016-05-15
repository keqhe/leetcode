
//the naive method is to count the number of islands (using BFS or DFS) for each board
//correct technique is union find: https://github.com/keqhe/leetcode/blob/master/round2/leetcode305.cpp
//union take O(1) and find take O(logN)
class Solution {
public:
    int find(vector<int> & parents, int curr) {
        while (curr != parents[curr]) {
            parents[curr] = parents[parents[curr]];//path compression
            curr = parents[curr];
        }
        return curr;
    }
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<int> res;
        if (m == 0 || n == 0)
            return res;
        int len = positions.size();
        int temp[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int count = 0;
        vector<int> parents(m*n, -1);//-1 means non-island cells
        for (int i = 0; i < len; i ++) {
            int x = positions[i].first;
            int y = positions[i].second;
            int curr = x*n + y;//NOT x*m + y;
            parents[curr] = curr;
            count ++;
            //check all of its neighbors
            for (auto p: temp) {
                int i = x + p[0];
                int j = y + p[1];
                int neighbor = i*n + j;
                if (i >= 0 && i < m && j >= 0 && j < n && parents[neighbor] != -1) {
                    int neighbor_parent = find(parents, neighbor);
                    if (curr != neighbor_parent) {//union
                        parents[curr] = neighbor_parent;
                        curr = neighbor_parent;
                        count --;
                    }
                }
            }
            res.push_back(count);
        }
        return res;
    }
};
