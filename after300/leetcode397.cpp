class Solution {
public:
    //dp[i] = min(dp(i-1), dp(i+1))
    int helper(int n, unordered_map<int, int>&m) {
        if (n == 1)
            return 0;
        if (m.find(n) != m.end())
            return m[n];
        int num = numeric_limits<int>::max();
        if (n % 2 == 0) {
            num = min(num, integerReplacement(n/2) + 1);
        }
        else {
            if (n < numeric_limits<int>::max()) {
                int x = min(integerReplacement(n-1), integerReplacement(n+1))+1;
                num = min(num, x);
            }
            else {
                int x = integerReplacement(n-1);
                num = min(num, x);
            }
        }
        m[n] = num;
        return num;
    }
    int integerReplacement(int n) {
        unordered_map<int, int> m;
        return helper(n, m);
    }
};
