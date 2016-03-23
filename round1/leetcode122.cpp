
class Solution {
public:
    //This problem can be viewed as finding all ascending sequences. For example, given {5, 1, 2, 3, 4}, buy at 1 & sell at 4 is the same as buy at 1 &sell at 2 & buy at 2& sell at 3 & buy at 3 & sell at 4.
    //stock I, only one transaction allowed, dp[i] = max(dp[i-1], prices[i] - min_tillnow)
    //stock II, as many as transactions you want, so that is finding all ascending sequences
    
    int maxProfit(vector<int>& prices) {
        int total = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] - prices[i-1] > 0)
                total += prices[i] - prices[i-1];
        }
        
        return total;
    }
};
