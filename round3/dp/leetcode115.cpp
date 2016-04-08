
class Solution {
public:
    //let dp[i][j] denote the number of distinct subsequences of T[0..i-1] in S[0..j-1]
    //when t[i-1] == s[j-1], dp[i][j] = dp[i][j-1] + dp[i-1][j-1]
    int numDistinct_2D(string s, string t) {
        if (s.length() < t.length())
            return 0;
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int j = 0; j <= m; j ++)
            dp[0][j] = 1;//null string is a subsequence of any string
        for (int i = 1; i <= n; i ++)
            dp[i][0] = 0;//any non-null string is NOT a subsequence of a null string
        for (int i = 1; i <= n; i ++) {
            for (int j = 1; j <= m; j ++) {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
                else 
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp[n][m];
    }
    int numDistinct(string s, string t) {
        if (s.length() < t.length())
            return 0;
        int m = s.length();
        int n = t.length();
        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        for (int i = 0; i <= n; i ++) {
            for (int j = 0; j <= m; j ++) {
                if (i == 0)
                    dp[i&1][j] = 1;
                else if (j == 0)
                    dp[i&1][j] = 0;
                else {
                    if (s[j-1] == t[i-1])
                        dp[i&1][j] = dp[i&1][j-1] + dp[(i-1)&1][j-1];
                    else
                        dp[i&1][j] = dp[i&1][j-1];
                }
            }
        }
        return dp[n&1][m];
    }
    
};
