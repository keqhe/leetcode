
class Solution {
public:
    //7 = 3 + 4
    //8 = 4 + 4
    //9 = 4 + 5
    //10 = 5 + 5
    //dp[i] = max(dp[i-j]*dp[j]) for all possible j
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; i ++) {
            for (int j = 1; j < i; j ++) {
                dp[i] = max(dp[i], max(j, dp[j])*max(i-j, dp[i-j]));
            }
        }
        return dp[n];
    }
};
