
class Solution {
public:
    /*dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + costs[i][0];
      dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + costs[i][1];
      dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + costs[i][2];
      */
    int minCost_more_space(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int m = costs.size();
        int n = costs[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = costs[0][0];
        dp[0][1] = costs[0][1];
        dp[0][2] = costs[0][2];
        for (int i = 1; i < m; i ++) {
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + costs[i][2];
        }
        return min(dp[m-1][0], min(dp[m-1][1], dp[m-1][2]));
    }
    //how to reduce the above method's space complexity to O(1)?
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int m = costs.size();
        int n = costs[0].size();
        int c0 = costs[0][0];
        int c1 = costs[0][1];
        int c2 = costs[0][2];
        /* think why the following is WRONG
        for (int i = 1; i < m; i ++) {
            c0 = min(c1, c2) + costs[i][0];
            c1 = min(c0, c2) + costs[i][1];
            c2 = min(c0, c1) + costs[i][2];
        }*/
        for (int i = 1; i < m; i ++) {
            int tmp_c0 = c0; 
            int tmp_c1 = c1;
            int tmp_c2 = c2;
            c0 = min(tmp_c1, tmp_c2) + costs[i][0];
            c1 = min(tmp_c0, tmp_c2) + costs[i][1];
            c2 = min(tmp_c0, tmp_c1) + costs[i][2];
        }
        return min(c0, min(c1, c2));
    }
};
