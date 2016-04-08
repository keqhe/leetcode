
class Solution {
public:
    //first thought: dp[i] denote the max profit we can get if we buy on day i, well the time complexity is O(n^2), the same as the brute force method
    
    //let dp[i] denote the max profit ending at most at day i (ie, selling at day i)
    //so dp[i] = max(dp[i-1], prices[i]-min_buy)
    //time complexity is O(n)
    int maxProfit_dp_method1(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> dp(prices.size(), 0);
        int min_buy = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            dp[i] = max(dp[i-1], prices[i]-min_buy);
            min_buy = min(min_buy, prices[i]);
        }
        return dp[prices.size()-1];
    }
    //dp[i] denote the max profit we can get at day i (we either sell it on day i or we keep it)
    //dp[i] = max(0, dp[i-1] + prices[i]-prices[i-1])
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> dp(prices.size(), 0);
        dp[0] = 0;
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i ++) {
            dp[i] = max(0, dp[i-1]+prices[i]-prices[i-1]);
            maxProfit = max(maxProfit, dp[i]);
        }
        return maxProfit;
    }
};
