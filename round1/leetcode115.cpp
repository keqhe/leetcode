
class Solution {
public:
    //ref: https://leetcode.com/discuss/48208/lines-solutions-with-detailed-explanations-time-and-space
    //let dp[i][j] denote the number of distinct subsequences of t[0...i-1] in s[0..j-1].
    //so, because if t is empty, there is only 1 subsequence (deleting all chars in s), so dp[0][j] = 1;
    //if s is empty and t is non-empty, there is 0 subsequences of t in s, so dp[i][0] = 0, where 1<=i<=m
    //
    int numDistinct(string s, string t) {
        int m = t.length();
        int n = s.length();
        vector<vector<int>> dp (m+1, vector<int> (n+1, 0));
        for (int j = 0; j <= n; j ++)
            dp[0][j] = 1;
        for (int i = 1; i <= m; i ++)
            dp[i][0] = 0;//note dp[0][0] is still 1
        for (int i = 1;i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (s[j-1] != t[i-1])
                    dp[i][j] = dp[i][j-1];
                else {
                    dp[i][j] = dp[i-1][j-1] + //with s[j-1]
                        dp[i][j-1];//without s[j-1]
                }
            }
        }
        
        return dp[m][n];
    }
};
