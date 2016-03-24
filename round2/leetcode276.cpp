
class Solution {
public:
    //https://leetcode.com/discuss/62689/simple-java-solution-for-with-time-and-space-can-reduced-space
    //dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-1)
    //        dp[i-2]*(k-1): when i and i-1 the same color
    //        dp[i-1]*(k-1): when i and i-1 not the same color
    int numWays(int n, int k) {
        if (n == 0 || k == 0)
            return 0;
        if ( n == 1)
            return k;
        vector<int> dp(n, 0);
        dp[0] = k;
        dp[1] = k*k;
        for (int i = 2; i < n; i ++) {
            dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-1);
        }
        return dp[n-1];
    }
};
