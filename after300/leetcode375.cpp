
class Solution {
public:
    //minmax algorithms
    //https://discuss.leetcode.com/topic/52164/solution-for-follow-up-with-explanation
    //http://www.cnblogs.com/grandyang/p/5677550.html
    //minimizing the loss in case of facing the worst case at each step
    //dp[i,j] = min(max(dp[i, k-1], dp[k+1, j]) + k), for i<k<j;
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for (int l = 1; l < n; l ++) {
            for (int i = 1; i +l <= n; i ++) {
                int j = i + l;
                dp[i][j] = min(dp[i+1][j] + i, dp[i][j-1]+j);
                for (int k = i+1; k < j; k ++) {
                    dp[i][j] = min(dp[i][j], max(dp[i][k-1], dp[k+1][j])+k);
                }
            }
        }
        return dp[1][n];
    }
};
