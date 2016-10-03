
class Solution {
public:
    /*
    n = 0, 1
    n = 1, 10
    n = 2, 9*9 + 10
    n = 3, 9*9*8 + dp[2]
    */
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        if (n == 1)
            return 10;
        if (n == 2)
            return 9*9+10;
        vector<int> dp(n+1, 0);
        dp[1] = 10;
        dp[2] = 9*9;
        int leftover = 8;
        for (int i = 3; i <= n; i ++) {
            if (leftover > 0) {
                dp[i] = dp[i-1]*leftover;
            }
            leftover --;
        }
        int sum = 0;
        for (int i = 1; i <= n; i ++)
            sum += dp[i];
        return sum;
    }
};
