
class Solution {
public:
    //median: https://leetcode.com/discuss/66401/the-only-person-dont-know-median-could-give-shortest-distance
    //ref: https://leetcode.com/discuss/78220/16ms-easy-understandable-c-solution
    int minTotalDistance(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> rows;
        vector<int> cols;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (grid[i][j] == 1) {
                    rows.push_back(i);
                    cols.push_back(j);
                }
            }
        }
        //sort(rows.begin(), rows.end())
        sort(cols.begin(), cols.end());
        int row_median = rows[rows.size()/2];
        int col_median = cols[cols.size()/2];
        
        int res = 0;
        for (auto & x : rows)
            res += abs(x-row_median);
        for (auto & y : cols) 
            res += abs(y - col_median);
        return res;
    }
};
