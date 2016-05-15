
class Solution {
public:
    //also check https://github.com/keqhe/leetcode/blob/master/round2/leetcode296.cpp
    //which uses sort
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row;
        vector<int> col;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    row.push_back(i);
                }
            }
        }
        int x = row[row.size()/2];
        for (int j = 0; j < n; j ++) {
            for (int i = 0; i < m; i ++) {
                if (grid[i][j] == 1) {
                    col.push_back(j);
                }
            }
        }
        int y = col[col.size()/2];
        cout << x << " " << y << endl;
        int total = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    total += abs(i-x) + abs(j-y);
                }
            }
        }
        return total;
    }
};
