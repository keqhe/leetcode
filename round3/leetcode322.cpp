
class Solution {
public:
    //[1,2,5], amount=3
  ////let dp[i] denote the fewest number coins for money amount of i
//dp[i] = min(dp[i], dp[j]+1), (i-j) should be the coin array

//vector<int> (amount+1, amount+1); the second amount+1 represents "no solution"
//dp[i] = 1 for all i's in coins array
//dp[0] = 0;
//dp[i] = min(dp[i], dp[i-coins[j]]+1), for all j where i-coins[j]] >= 0
    int coinChange(vector<int>& coins, int amount) {
        if (coins.empty())
          return 0;
        if (amount == 0)
          return 0;
        vector<int> dp(amount+1, amount+1);
        for (auto x: coins)
            if (x <= amount)
                dp[x] = 1;
        dp[0] = 0;
        for (int i = 1; i <= amount; i ++) {
          for (int j = 0; j < coins.size(); j ++) {
            if (i - coins[j] >= 0) {
              dp[i] = min(dp[i], dp[i - coins[j]]+1);
            }
          }
        }
        return dp[amount] == amount+1 ? -1: dp[amount];
    }
};
