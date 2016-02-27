#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    //dynamic programming
    //ref; https://leetcode.com/discuss/79767/java-easy-version-to-understand
    //ref: https://leetcode.com/discuss/73617/7-line-java-only-consider-sell-and-cooldown
    //sell[i]: the maximal profit if i sell on day i
    //cooldown[i]: the maximal profit if I cooldown on day i
    //then sell[i+1] = max(cooldown[i], sell[i-1]+prices[i]-prices[i-1])
    //cooldown[i+1] = max(sell[i], cooldown[i])
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int len = prices.size();
        vector<int> sell(len, 0);
        vector<int> cooldown(len, 0);
        sell[0] = 0;
        cooldown[0] = 0;
        for (int i = 1; i < len; i ++) {
            sell[i] = max(sell[i-1]+prices[i]-prices[i-1], cooldown[i-1]);
            /*sell[i-1]+prices[i]-prices[i-1]: sell on day i-1, but buy on day i-1 and sell it on day i;
              in this case, sell[i-1] is a "virtual sell", you do not really sell it
              cooldown[i-1]: buy it on day i and sell it on day i
            */
            cooldown[i] = max(cooldown[i-1], sell[i-1]);
        }
        
        return max(sell[len-1], cooldown[len-1]);
    }
};

int main() {
	class Solution sn;
	return 0;
}
