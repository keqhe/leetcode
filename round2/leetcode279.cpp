
class Solution {
public:
    //ref: https://leetcode.com/discuss/62526/an-easy-understanding-dp-solution-in-java
    //dp[i] = min(dp[i], 1 + dp[i-j*j]), 1 <= j and j*j <= i;
    int numSquares(int n) {
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for (int i = 1; i*i <= n; i ++) {
            dp[i*i] = 1;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j*j <= i; j ++) {
                dp[i] = min(dp[i], 1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
    //my first thought
    int numSquares_first(int n) {
        vector<int> dp (n+2, n);
        for (int i = 1; i*i <= n; i ++) {
            dp[i*i] = 1;
        }
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; i+j <=n; j ++) {
                if (dp[i] + dp[j] < dp[i+j]) {
                    dp[i+j] = dp[i] + dp[j];
                }
            }
        }
        return dp[n];
    }
};
