
class Solution {
public:
    //let dp[t][i] denote the max profit with at most t transactions for range [0..i]
    //dp[0][i] = 0, dp[t][0] = 0
    //dp[t][i] = max(dp[t][i-1], dp[t-1][i], dp[t-1][j]+prices[i]-prices[j]), where 0<=j<i
    int maxProfit(int k, vector<int>& prices) {
        if (k == 0 || prices.size() < 2)
            return 0;
        //becomes stock II
        if (k >= prices.size()/2) {
            int sum = 0;
            for (int i = 1; i < prices.size(); i ++) {
                if (prices[i] > prices[i-1])
                    sum += prices[i]-prices[i-1];
            }
            return sum;
        }
        int size = prices.size();
        vector<vector<int>> dp(k+1, vector<int>(size, 0));
        
        for (int i = 0; i < size; i ++)
            dp[0][i] = 0;
        for (int t = 0; t <= k; t ++)
            dp[t][0] = 0;
        /*the following logic is TLE
        for (int t = 1; t <= k; t ++) {
            for (int i = 0; i < size; i ++) {
                for (int j = 0; j < i; j ++) {
                    dp[t][i] = max(dp[t][i-1], max(dp[t-1][i], dp[t-1][j]+prices[i]-prices[j]));
                }
            }
        }
        */
        for (int t = 1; t <= k; t ++) {
            int local = dp[t-1][0] - prices[0];
            for (int i = 0; i < size; i ++) {
                dp[t][i] = max(max(dp[t-1][i], dp[t][i-1]), prices[i]+local);
                local = max(local, dp[t-1][i] - prices[i]);
            }
        }
        return dp[k][size-1];
    }
};
