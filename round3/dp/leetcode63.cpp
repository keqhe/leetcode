
class Solution {
public:
    /*  if obstacleGrid[i][j] == 0, dp[i][j] = 0;
        else {
            dp[i][j] = dp[i-1][j] + dp[i][j-1])
        }
    */
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        
        //init first col
        for (int i = 0; i < m; i ++) {
            if (i == 0) {
                dp[i][0] = obstacleGrid[i][0] == 1? 0 : 1;
            }
            else {
                dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i-1][0];
            }
        }
        //init first row
        for (int j = 1; j < n; j ++) {
            dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j-1];
        }
        //dp
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = obstacleGrid[i][j] == 1 ? 0 : dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};
