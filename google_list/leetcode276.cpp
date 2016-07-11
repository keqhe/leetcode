
class Solution {
public:
    //dp[i] denote how many choices we have for post i
    //dp[0] = 1;
    //dp[1] = k;
    //dp[i] = dp[i-2]*(k-1) [i-1 and i have same color] + dp[i-1](k-1) [i-1 and i have different colors]
    int numWays(int n, int k) {
        if (n <= 0 || k <= 0)
            return 0;
        if (n == 1)
            return k;
        if (n > 2 && k == 1)
            return 0;
        vector<int> dp(n+1, 0);
        dp[1] = k;
        dp[2] = k*k;
        for (int i = 3; i <= n; i ++)
            dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-1);
        return dp[n];
    }
};
