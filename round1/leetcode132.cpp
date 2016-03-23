
class Solution {
public:
    //reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-palindrome-partitioning-i-ii.html
    //Basic idea: use dp[i] to denote the min cut of string s[0:i-1]
    //dp[i] = min(dp[i], d[j] + 1) for 0<= j <=i-1, and s[j:i-1] is palindrome
    int minCut(string s) {
        int n = s.length();
        if (n <= 1)
            return 0;
        vector<vector<bool>> isPal(n, vector<bool> (n, false));
        for (int i = n-1; i >= 0; i --) {
            for (int j = i; j < n; j ++) {
                if (i == j) isPal[i][j] = true;
                else if (j == i + 1 && s[i] == s[j])
                    isPal[i][j] = true;
                else if (isPal[i+1][j-1] && s[i] == s[j])
                    isPal[i][j] = true;
            }
        }
        vector<int> dp (n+1, numeric_limits<int>::max());
        dp[0] = -1;//think about the case the s's len is 1
        for (int i = 1; i <= n; i ++) {
            for (int j = i-1; j >= 0; j --) {
                if (isPal[j][i-1]) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[n];
    }
};
