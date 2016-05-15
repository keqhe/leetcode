
class Solution {
public:
    int nthUglyNumber_method1(int n) {
        if (n == 1)
            return 1;
        queue<int> q2;
        queue<int> q3;
        queue<int> q5;
        
        q2.push(1);
        q3.push(1);
        q5.push(1);
        int curr;
        for (int i = 0; i < n; i ++) {
            curr = min(q2.front(), min(q3.front(), q5.front()));
            if (curr == q2.front())
                q2.pop();
            if (curr == q3.front())
                q3.pop();
            if (curr == q5.front())
                q5.pop();
            q2.push(curr*2);
            q3.push(curr*3);
            q5.push(curr*5);
        }
        return curr;
    }
    
    int nthUglyNumber(int n) {
        vector<int> primes = {2,3,5};
        vector<int> index(3, 1);
        vector<int> dp(n+1, 1);
        
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
