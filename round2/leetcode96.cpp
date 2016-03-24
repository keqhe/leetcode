
class Solution {
public:
    //idea, dynamic programming
    //dp[0] = 1; dp[1] = 1, dp[2] = 2 (dp[2] = dp[0]*dp[1]+dp[1]*dp[0])
    int numTrees(int n) {
        if (n == 0)
            return 0;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i ++) {
            for (int j = 0; j < i; j ++) {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};
