
class Solution {
public:
    ////ref: https://leetcode.com/discuss/85709/easy-to-understand-dp-solution
    //denote forward[i] is the max profit in [0..i], i.e., ending at most on day i, one transaction at most
    //denote backward[i] is the max profit in [i...len-1], i.e., starting at as early as on day i,one transaction at most
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<int> forward(prices.size(), 0);
        vector<int> backward(prices.size(), 0);
        
        forward[0] = 0;
        int min_buy = prices[0];
        for (int i = 1; i < prices.size(); i ++) {
            forward[i] = max(forward[i-1], prices[i] - min_buy);
            min_buy = min(min_buy, prices[i]);
        }
        
        for (int i = 0; i < prices.size(); i ++)
            cout << forward[i] << " ";
        cout << endl;
        
        backward[prices.size()-1] = 0;
        int max_sell = prices[prices.size()-1];
        for (int i = prices.size()-2; i >= 0; i --) {
            backward[i] = max(max_sell - prices[i], backward[i+1]);
            max_sell = max(max_sell, prices[i]);
        }
        
        for (int i = 0; i < prices.size(); i ++)
            cout << backward[i] << " ";
        cout << endl;
        
        int res = 0;
        for (int i = 0; i < prices.size(); i ++) {
            res = max(res, forward[i]+backward[i]);
        }
        return res;
    }
};
