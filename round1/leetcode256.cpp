
class Solution {
public:
    //dp[i][j] is the cost of paiting house i with color j
    //dp[i+1][0] = min(dp[i][1], dp[i][2])
    //dp[i+1][1] = min(dp[i][0], dp[i][2])
    //dp[i+1][2] = min(dp[i][0], dp[i][1])
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty() || costs[0].empty())
            return 0;
        int m = costs.size();
        vector<vector<int>> dp(m, vector<int>(3, 0));
        for (int j = 0; j < 3; j ++)
            dp[0][j] = costs[0][j];
        for (int i = 0; i < m-1; i ++) {
            dp[i+1][0] = min(dp[i][1], dp[i][2]) + costs[i+1][0];
            dp[i+1][1] = min(dp[i][0], dp[i][2]) + costs[i+1][1];
            dp[i+1][2] = min(dp[i][0], dp[i][1]) + costs[i+1][2];
        }
        return min(dp[m-1][0], min(dp[m-1][1], dp[m-1][2]));
    }
};
