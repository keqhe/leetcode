
class Solution {
public:
    //sell[i] denote the max profit we can get if we sell on day i
    //cooldown[i] denote the max profit we can get if we cooldown on day i
    /* sell[i]=max(sell[i]+prices[i]-prices[i-1], cooldown[i-1])
       cooldown[i] = max(cooldown[i-1], sell[i-1])
    */
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> sell(prices.size(), 0);
        vector<int> cooldown(prices.size(), 0);
        sell[0] = 0;
        cooldown[0] = 0;
        for (int i = 1; i < prices.size(); i ++) {
            sell[i] = max(sell[i-1] + prices[i] - prices[i-1], cooldown[i-1]);
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
        }
        return max(sell[prices.size()-1], cooldown[prices.size()-1]);
    }
};
