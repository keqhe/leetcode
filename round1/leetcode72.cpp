
class Solution {
public:
    //dynamic program, Facebook wenfei...
    //ref: https://leetcode.com/discuss/59043/simple-and-clean-java-dp-solution-with-comments
    //idea; dp[i][j] means the number of steps to convert word1[0:i-1] to word2[0:j-1]
    //dp[i][0], where word1 has i chars and word2=""; so we need i deletions
    //dp[0][j], whre word1="" and word2 has j chars; so we need j insertions
    //dp[i][j] = min(dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+delta)
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int i = 0; i <= m; i ++)
            dp[i][0] = i;
        for (int j = 0; j <= n; j ++)
            dp[0][j] = j;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++ ) {
                int delta = (word1[i-1] == word2[j-1] ? 0 : 1);
                dp[i][j] = min(min(dp[i][j-1]+1, dp[i-1][j]+1), dp[i-1][j-1]+delta);
            }
        }
        
        return dp[m][n];
    }
};
