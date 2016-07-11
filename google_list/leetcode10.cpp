
class Solution {
public:
    /*
    note: ""
          ".*"
          should return true
          this means when i == 0 and j > 0, we may still return true
    */
    //dp[i][j] denotes whether s[0..i-1] and p[0..j-1]
    bool isMatch(string s, string p) {
        if (s == p)
            return true;
        //if (s.empty() || p.empty())
        //    return false; //this is WRONG
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                /*else if (i == 0) {
                    dp[i][j] = false;
                }*/ //this is WRONG
                else if (j == 0) {
                    dp[i][j] = false;
                }
                else {
                    if (p[j-1] != '*') {
                        dp[i][j] = i > 0 && dp[i-1][j-1] && (p[j-1] == s[i-1] || p[j-1] == '.');
                    }
                    else {//* can not appear at position 0 in p, so j >= 2
                        //isMatch("aab", "c*a*b") → true
                        //dp[i][j-2] matches zero preceding chars
                        dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                    }
                }
            }
        }
        return dp[m][n];
    }
};
