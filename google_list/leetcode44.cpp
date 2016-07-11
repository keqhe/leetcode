
class Solution {
public:
    //let dp[i][j] denote whether s[0..i-1] and p[0..j-1] is matchable
    //'*' Matches any sequence of characters (including the empty sequence).
    bool isMatch(string s, string p) {
        if (s == p)
            return true;
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (j == 0)
                    dp[i][j] = false;
                else {
                    if (p[j-1] != '*') {
                        dp[i][j] = (i>0) && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                    }
                    else {
                        //'*' Matches any sequence of characters (including the empty sequence).
                        dp[i][j] = j > 0 && dp[i][j-1] || i > 0 && dp[i-1][j]; 
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};
