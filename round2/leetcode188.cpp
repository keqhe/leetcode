
class Solution {
public:
    //https://leetcode.com/discuss/62026/clean-java-dp-solution-with-comment
    //https://leetcode.com/discuss/62026/clean-java-dp-solution-with-comment
    //ref: https://leetcode.com/discuss/25627/dp-o-kn-time-o-n-space-cpp-solution
    //dp[k][i] denotes the max profit using data[0...i] with at most k transactions
    //dp[0][i] is 0 because there is 0 transaction
    //dp[k][0] is 0 because there is no profit if there is only 1 data point
    //dp[k][i] = max(dp[k][i-1],dp[k-1][i],max(dp[k-1][j]+prices[i]-prices[j]))
    //           = max(dp[k][i-1], dp[k-1][i], prices[i]+max(dp[k-1][j]-prices[j])) where 0<=j<i
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() <= 1 || k == 0)
            return 0;
        if (k >= prices.size()/2) {//this becomes stock problem II, think why
            int max_profit = 0;
            for (int i = 1; i < prices.size(); i ++) {
                int diff = prices[i] - prices[i-1];
                max_profit += (diff > 0 ? diff : 0); 
            }
            return max_profit;
        }
        
        int len = prices.size();
        vector<vector<int>> dp(k+1, vector<int>(len, 0));
        for (int t = 1; t <= k; t ++) {
            int localMax = dp[t-1][0] - prices[0];
            for (int i = 1; i < len; i ++) {
                dp[t][i] = max(max(dp[t][i-1], dp[t-1][i]), prices[i]+localMax);
                localMax = max(localMax, dp[t-1][i]-prices[i]);
            }
        }
        
        return dp[k][len-1];
    }
};
