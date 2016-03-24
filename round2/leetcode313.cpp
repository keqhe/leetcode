
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int size = primes.size();
        vector<int> index(size, 1);
        
        for (int i = 2; i <= n; i ++) {
            dp[i] = dp[index[0]]*primes[0];
            for (int j = 1; j < primes.size(); j ++) {
                dp[i] = min(dp[i], dp[index[j]]*primes[j]);    
            }
            for (int j = 0; j < primes.size(); j ++) {
                if (dp[i] == dp[index[j]]*primes[j])
                    index[j] ++;
            }
        }
        return dp[n];
    }
};
