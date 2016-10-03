
class Solution {
public:
    //an ugly number comes from an ugly number times an value in primes
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        vector<int> index(size, 0);
        vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i = 1; i < n; i ++) {
            dp[i] = dp[index[0]]*primes[0];
            for (int j = 1; j < size; j ++) {
                dp[i] = min(dp[i], dp[index[j]]*primes[j]);
            }
            
            for (int j = 0; j < size; j ++) {
                if (dp[i] == dp[index[j]]*primes[j])
                    index[j] ++;
            }
        }
        return dp[n-1];
    }
};
