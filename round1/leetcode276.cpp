
class Solution {
public:
    //w(n) = (k-1)*w(n-1) , when color(n-1) != color(n-2) 
    //    + (k-1)*w(n-2), when color(n-1) == color(n-2)
    //https://leetcode.com/discuss/62689/simple-java-solution-for-with-time-and-space-can-reduced-space
    int numWays(int n, int k) {
        if (n == 0 || k == 0)
            return 0;
        vector<int> dp (n, 0);
        for (int i = 0; i < n; i ++) {
            if (i == 0)
                dp[0] = k;
            else if (i == 1)
                dp[1] = k*k;
            else
                dp[i] = dp[i-2]*(k-1) + dp[i-1]*(k-1);
        }
        return dp[n-1];
    }
};
