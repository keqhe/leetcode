
class Solution {
public:
    //dp[i][j] means whether s[0..i-1] matches p[0..j-1]
    /*
        dp[0][0] = true;
    */
    /*
        if (p[j-1] != '*')
            dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?')
        else {
            dp[i][j] = dp[i][j-1] || dp[i-1][j];//dp[i][j-1] means "*" matches empty sequence
            //dp[i-1][j] means '*' matches at least 1 char
        }
    */
    bool isMatch_2D(string s, string p) {
        if (s.empty() && p.empty())
            return true;
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;//null string matches null string
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (j > 0 && p[j-1] != '*') {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
                else if (j > 0 && p[j-1] == '*') {
                    dp[i][j] = dp[i][j-1] || (i > 0) && dp[i-1][j];
                }
            }
        }
        return dp[m][n];
    }
    
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty())
            return true;
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(2, vector<bool>(n+1, false));
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 && j == 0)
                    dp[i&1][j] = true;
                else if (i > 0 && j == 0) //if we do not have this, it is WRONG, think why
                    dp[i&1][j] = false;
                else if (j > 0 && p[j-1] != '*') {
                    dp[i&1][j] = (i > 0) && dp[(i-1)&1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
                else if (j > 0 && p[j-1] == '*') {
                    dp[i&1][j] = dp[i&1][j-1] || (i > 0) && dp[(i-1)&1][j];
                }
            }
        }
        return dp[m&1][n];
    }
};
