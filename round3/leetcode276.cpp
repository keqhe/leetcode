
class Solution {
public:
    /*
    no more than 2 adjacent posts have the same color
    if i and i-1 has the same color
    if i and i-1 do not have the same color
    dp[i-2]*(k-1), i and i-1 have the same color
    dp[i-1]*(k-1), i and i-1 do not have the same color
    dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-1);
    */
    
    int numWays(int n, int k) {
        if (n == 0 || k == 0)
            return 0;
        vector<int> dp(n+1, 0);
        dp[1] = k;
        dp[2] = k*k;
        for (int i = 3; i <= n; i ++)
            dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-1);
        return dp[n];
    }
};
