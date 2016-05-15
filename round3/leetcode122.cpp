
class Solution {
public:
    //note, you can sell a stcok in hand first and then buy in on the same day
    //for on day i, you buy it for $5, day (i+1), the stock price is $10, you can first sell it and then buy on day (i+1) with $10
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int init = prices[0];
        int sum = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] > prices[i-1])
                sum += prices[i] - prices[i-1];
        }
        return sum;
    }
};
