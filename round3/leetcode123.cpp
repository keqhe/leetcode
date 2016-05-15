
class Solution {
public:
    //let forward[i] denote the max profit we can get for 1 transaction ending at most on day i
    //let backward[i] denote the max profit we can get for 1 transaction starting at early on day i
    //the the max profit with at most 2 transactions, if max(forward[i]+backward[i]) for all valid i's
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int n = prices.size();
        vector<int> forward(n, 0);
        int min_buy = prices[0];
        for (int i = 1; i < n; i ++) {
            forward[i] = max(forward[i-1], prices[i]-min_buy);
            min_buy = min(min_buy, prices[i]);
        }
        
        vector<int> backward(n, 0);
        int max_sell = prices[n-1];
        for (int i = n-2; i >= 0; i --) {
            backward[i] = max(backward[i+1], max_sell - prices[i]);
            max_sell = max(max_sell, prices[i]);
        }
        
        int maxP = 0;
        for (int i = 0; i < n; i ++) {
            maxP = max(maxP, forward[i] + backward[i]);
        }
        return maxP;
    }
};
