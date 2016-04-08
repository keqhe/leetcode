
class Solution {
public:
    /*denote dp[i][j] as s1[0..i-1] and s2[0..j-1] can form s2[0..i+j-1]
    int m = s1.length();
    int n = s2.length();
     dp[0][0] = true;
     for (int j = 1; j <= n; j ++) {
        dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
     }
     for (int i = 1; i <= m; i ++) {
         dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
     }
     for (int i = 1; i <= m; i ++) {
         for (int j = 1; j <= n; j ++) {
             dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1] ||
                        dp[i][j-1] && s2[j-1] == s3[i+j-1];
         }
     }
     return dp[m][n];
     */
    //method 1, 2D DP
    bool isInterleave_2D(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int m = s1.length();
        int n = s2.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int j = 1; j <= n; j ++) {
            dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
        }
        for (int i = 1; i <= m; i ++) {
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1] ||
                        dp[i][j-1] && s2[j-1] == s3[i+j-1];
            }
        }
        return dp[m][n];
    }
    //the above can be reduced to O(n) space?
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int m = s1.length();
        int n = s2.length();
        vector<bool> dp(n+1, false);
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0) {
                    dp[j] = j == 0 ? true : dp[j-1] && s2[j-1] == s3[0+j-1];
                }   
                else if (j == 0) {
                    dp[j] = i == 0 ? true : dp[j] && s1[i-1] == s3[i+0-1];
                }
                else {
                    dp[j] = dp[j] && s1[i-1] == s3[i+j-1] ||
                            dp[j-1] && s2[j-1] == s3[i+j-1];
                }
            }
        }
        return dp[n];
    }
};
