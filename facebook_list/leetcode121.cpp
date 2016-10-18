
class Solution {
public:
    //
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int min_val = numeric_limits<int>::max();
        int max_profit = 0;
        for (int i = 0; i < prices.size(); i ++) {
            if (prices[i] > min_val) {
                max_profit = max(max_profit, prices[i] - min_val);
            }
            min_val = min(min_val, prices[i]);
        }
        return max_profit;
    }
    
};
