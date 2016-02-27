#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //the first though i have, but it is wrong, because this answer should for stock II
    int maxProfit_actually_stockII(vector<int>& prices) {
        int sum = 0;
        for (int i = 1; i < prices.size(); i ++) {
            if (prices[i] >= prices[i-1]) {
                sum += prices[i] - prices[i-1];
            }
        }
        return sum;
    }
    //dp[i] = max(0, dp[i-1] + (prices[i] - prices[i-1]))
    int maxProfit_thought2(vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<int> dp(prices.size(), 0);
        int largest = 0;
        dp[0] = 0;
        for (int i = 1; i < prices.size(); i ++) {
            dp[i] = max(0, dp[i-1] + (prices[i] - prices[i-1]));
            largest = max(dp[i], largest);
        }
        
        return largest;
    }

    //another method
    //denote dp[i] as the max profit between [0...i], ending at most on day i, one transaction allowed at most
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        vector<int> dp(prices.size(), 0);
        dp[0] = 0;
        int min_buy = prices[0];
        for (int i = 0; i < prices.size(); i ++) {
            dp[i] = max(dp[i-1], prices[i] - min_buy);
            min_buy = min(min_buy, prices[i]);
        }
        
        return dp[prices.size()-1];
    }
};

int main() {
	class Solution sn;
	return 0;
}
