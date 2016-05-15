
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n+1, 1);
        int len = primes.size();
        vector<int> index(len, 1);
        dp[1] = 1;//1 is the first super ugly number according to definition
        for (int i = 2; i <= n; i ++) {
            dp[i] = dp[index[0]]*primes[0];
            
            for (int j = 1; j < len; j ++) {
                dp[i] = min(dp[i], dp[index[j]]*primes[j]);
            }
            for (int j = 0; j < len; j ++) {
                if (dp[i] == dp[index[j]]*primes[j])
                    index[j] ++;
            }
        }
        return dp[n];
    }
};
