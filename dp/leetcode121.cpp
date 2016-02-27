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
    int maxProfit(vector<int>& prices) {
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
};

int main() {
	class Solution sn;
	return 0;
}
