
class Solution {
public:
    //let dp[i][j][k] denote whether s1[i..i+k-1] is scramble string of s2[j..j+k-1]
    /*
        dp[i][j][1] = (s1[i] == s2[j])
        dp[i][j][k] = dp[i][j][k] || dp[i][j][l] && dp[i+l][j+l][k-l] || dp[i][j+k-l][l] && dp[i+l][j][k-l], where 1<=l<k
    */
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        int m = s1.length();
        vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(m, vector<bool>(m+1, false)));
        
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < m; j ++) {
                dp[i][j][1] = (s1[i] == s2[j]);
            }
        }
        /*
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < m; j ++) {
                for (int k = 2; i+k <= m && j+k <= m; k ++) {
                    for (int l = 1; l < k; l ++) {
                            //think about an example, k = 5 and l = 3 and i = j = 0
                        dp[i][j][k] = dp[i][j][k] || dp[i][j][l] && dp[i+l][j+l][k-l] ||
                            dp[i][j+k-l][l] && dp[i+l][j][k-l];
                    }
                }
            }
        }
        */
        
        //think, why the above is WRONG?
        //why the loop's order matters? note when we calculate dp[i][j][k], we need to make sure 
        //dp[i][j][l], dp[i+l][j+l][k-l], dp[i][j+k-l][l], dp[i+l][j][k-l] have been calculated!
        for (int k = 2; k <= m; k ++) {
            for (int i = 0; i+k <= m; i ++) {
                for (int j = 0; j+k <= m; j ++) {
                    for (int l = 1; l < k; l ++) {
                            //think about an example, k = 5 and l = 3 and i = j = 0
                        dp[i][j][k] = dp[i][j][k] || dp[i][j][l] && dp[i+l][j+l][k-l] ||
                            dp[i][j+k-l][l] && dp[i+l][j][k-l];
                    }
                }
            }
        }
        
        return dp[0][0][m];
    }
};
