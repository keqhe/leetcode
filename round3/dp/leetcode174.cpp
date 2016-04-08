
class Solution {
public:
    /*think why the following is WRONG, using case : [[0 , 5], [-2,-3]], 
    the following returns 3
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty())
            return 0;
        int init = 0;
        
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = init + dungeon[0][0];
        int minH = dp[0][0] >= 0 ? 1 : 1-dp[0][0];
        
        for (int j = 1; j < n; j ++) {
            dp[0][j] = dp[0][j-1] + dungeon[0][j];
            minH = max(minH, dp[0][j] >= 0 ? 1 : 1-dp[0][j]);
        }
        for (int i = 1; i < m; i ++) {
            dp[i][0] = dp[i-1][0] + dungeon[i][0];
            minH = max(minH, dp[i][0] >= 0 ? 1 : 1-dp[i][0]);
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + dungeon[i][j];
                minH = max(minH, dp[i][j] >= 0 ? 1 : 1-dp[i][j]);
            }
        }
        return minH;
    }
    */
    //let dp[i][j] denote the minimal points needed to reach the destination (i.e., [m-1][n-1])
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if (dungeon.empty() || dungeon[0].empty())
            return 0;
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = dungeon[m-1][n-1] >= 0 ? 1 : 1-dungeon[m-1][n-1];
        
        
        //last row
        /*
            dp[m-1][j] + dungeon[m-1][j] == dp[m-1][j+1]
            dp[m-1][j] = max(1, dp[m-1][j+1]-dungeon[m-1][j])
        */
        for (int j = n-2; j >= 0; j --) {
            dp[m-1][j] = max(1, dp[m-1][j+1]-dungeon[m-1][j]);
        }
        //last col
        for (int i = m-2; i >= 0; i --) {
            dp[i][n-1] = max(1, dp[i+1][n-1]-dungeon[i][n-1]);
        }
        
        for (int i = m-2; i >= 0; i --) {
            for (int j = n-2; j >= 0; j --) {
                int next = min(dp[i+1][j], dp[i][j+1]);
                dp[i][j] = max(1, next-dungeon[i][j]);
            }
        }
        return dp[0][0];
    }
};
