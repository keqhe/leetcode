
class Solution {
public:
    bool isMatch(string s, string p) {
        if (s.empty() && p.empty())
            return true;
        int len1 = s.length();
        int len2 = p.length();
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                if (i == 0 && j == 0) {
                    dp[i][j] = true;
                }
                else if (j == 0) {
                    dp[i][j] = false;
                }
                else {
                    if (p[j-1] != '*') {
                        dp[i][j] = i > 0 && dp[i-1][j-1] && (p[j-1] == '?' || p[j-1] == s[i-1]);
                    }
                    else {
                        dp[i][j] = dp[i][j-1] || (i > 0 && dp[i-1][j]);
                    }
                }
            }
        }
        return dp[len1][len2];
    }
};
