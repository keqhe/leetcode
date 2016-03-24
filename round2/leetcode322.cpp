
class Solution {
public:
    //dp[i] = dp[i-j] + 1;
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty() || amount == 0)
            return 0;
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i ++) {
            for (auto x : coins) {
                if (i >= x) {
                    dp[i] = min(dp[i], dp[i-x]+1);
                }
            }
        }
        /*for (int i = 0; i <= amount; i ++)
            cout << dp[i] << " ";
        cout << endl;
        */
        return (dp[amount] == amount+1 ? -1 : dp[amount]);
    }
};
