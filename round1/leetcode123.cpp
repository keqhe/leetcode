
class Solution {
public:
    //[10, 8, 12, 9, 16]
    //find the maximal profit before i 
    //find the maximal profit after i
    //left to right: dp[i] = max(dp[i-1], p[i] - min_now)
    //right to left: dp[i] = max(dp[i+1], max_now - p[i])
    //people this call divide and conquer and dynamic programming
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0)
            return 0;
        vector<int> left (prices.size(), 0);
        vector<int> right (prices.size(), 0);
        
        left[0] = 0;
        int min_now = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            left[i] = max(left[i-1], prices[i] - min_now);
            min_now = min(min_now, prices[i]);
        }
        
        right[prices.size() - 1] = 0;
        int max_now = prices[prices.size() - 1];
        
        for (int i = prices.size() - 2; i >= 0; i --) {
            right[i] = max(right[i-1], max_now - prices[i]);
            max_now = max(max_now, prices[i]);
        }
        
        int max_profit = 0;
        for (int i = 0; i < left.size(); i ++) {
            max_profit = max(max_profit, left[i] + right[i]);
        }
        
        return max_profit;
    }
};
