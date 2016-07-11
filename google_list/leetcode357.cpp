
class Solution {
public:
    //math
    //https://discuss.leetcode.com/topic/47983/java-dp-o-1-solution/2
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0)
            return 1;
        vector<int> dp(n+1, 0);
        dp[1] = 10;//0, 1, 2,3,4,5,6,7,8,9
        dp[2] = 9*9;//
        
        int a = 8;
        // 3, 4, 5, 6, 7, 8, 9, 10
        // 8, 7, 6, 5, 4, 3, 2, 1
        for (int i = 3; i <= min(10, n); i ++) {
            dp[i] = dp[i-1]*a;
            a --;
        }
        int count = 0;
        for (int i = 1; i <= n; i ++) {
            count += dp[i];
        }
        return count;
    }
};
