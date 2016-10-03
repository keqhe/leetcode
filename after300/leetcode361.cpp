
class Solution {
public:
    //https://discuss.leetcode.com/topic/48565/short-o-mn-solution
    //dynamic programing
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();
        int rowhits = 0;
        vector<int> colhits(n);
        int max_enemy = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (j == 0 || grid[i][j-1] == 'W') {
                    rowhits = 0;//reset
                    for (int k = j; k < n && grid[i][k] != 'W'; k ++) {
                        rowhits += grid[i][k] == 'E';
                    }
                }
                if (i == 0 || grid[i-1][j] == 'W') {
                    colhits[j] = 0;
                    for (int k = i; k < m && grid[k][j] != 'W'; k ++) {
                        colhits[j] += grid[k][j] == 'E';
                    }
                }
                
                if (grid[i][j] == '0') {
                    max_enemy = max(max_enemy, rowhits + colhits[j]);
                }
            }
        }
        return max_enemy;
    }
};
