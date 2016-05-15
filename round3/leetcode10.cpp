
class Solution {
public:
    //let dp[i][j] denote whether s[0..i-1] matches p[0..j-1]
    /*dp[0][0] = true;
      dp[i][0] = false; for i > 0
      if (p[j-1] != '*')
        dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.')
      else 
        dp[i][j] = dp[i][j-2] (where * matches 0 preceding chars) || dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2] == '.')(where * matches 1 or more chars)
        //take s = "ab" and p = ".*" as an example , dp[1][1] = true, dp[2][2] = dp[2][0] || dp[1][2] =
        0 
        //dp[1][2] = dp[0][2] = dp[0][0] = true
    */
    bool isMatch_2D(string s, string p) {
        if (s.empty() && p.empty())
            return true;
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 && j == 0)   
                    dp[i][j] = true;
                else if (i > 0 && j == 0)
                    dp[i][j] = false;
                else if (j > 0) {
                    if (p[j-1] != '*')
                        dp[i][j] = (i > 0) && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                    else if (p[j-1] == '*')//p must not start with a '*' according to regular explression matching's definition
                        dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (s[i-1]==p[j-2] || p[j-2] == '.'));
                }
            }
        }
        return dp[m][n];
    }
    //reduce the space complexity to O(n)
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
                else if (i > 0 && j == 0)
                    dp[i&1][j] = false;
                else if (j > 0) {
                    if (p[j-1] != '*') {
                        dp[i&1][j] = (i > 0) && dp[(i-1)&1][j-1] && (s[i-1]==p[j-1] || p[j-1] == '.');
                    }
                    else if (p[j-1] == '*') {
                        dp[i&1][j] = dp[i&1][j-2] || (i > 0 && dp[(i-1)&1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                    }
                }
            }
        }
        return dp[m&1][n];
     }
};
