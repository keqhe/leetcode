
class Solution {
public:
    //median [0, 0, 0, 1] median is 0
    //[0 0 1 1] you can say it is 0 or 1, or 0.5, typically chose nums[nums.size()/2]
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        vector<int> row;
        vector<int> col;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j] == 1) {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }
        int r = row[row.size()/2];
        sort(col.begin(), col.end());
        int c = col[col.size()/2];
        int dist = 0;
        for (int i = 0; i < grid.size(); i ++) {
            for (int j = 0; j < grid[0].size(); j ++) {
                if (grid[i][j]) {
                    dist += abs(i-r) + abs(j-c);
                }
            }
        }
        return dist;
    }
};
