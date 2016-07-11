
class Solution {
public:
    //cooldown[i] = max(sell[i-1], cooldown[i-1])
    //sell[i] = max(sell[i-1]+prices[i]-prices[i-1], cooldown[i-1])
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int size = prices.size();
        vector<int> cooldown(size, 0);
        vector<int> sell(size, 0);
        
        for (int i = 1; i < size; i ++) {
            cooldown[i] = max(sell[i-1], cooldown[i-1]);
            sell[i] = max(sell[i-1]+prices[i]-prices[i-1], cooldown[i-1]);
        }
        
        return max(cooldown[size-1], sell[size-1]);
    }
};
