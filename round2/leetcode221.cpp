
class Solution {
public:
    //dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1 if matrix[i][j] == '1'
    //dp[i][j] denotes the max length of the square ending at position [i][j]
    //ref:https://leetcode.com/discuss/71792/java-easy-version-to-understand-use-dp
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int Max = 0;
        for (int i = 0; i < m; i ++) {
            dp[i][0] = matrix[i][0] - '0';
            Max = max(Max, dp[i][0]);
        }
        for (int j = 0; j < n; j ++) {
            dp[0][j] = matrix[0][j] - '0';
            Max = max(Max, dp[0][j]);
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else if (matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    Max = max(Max, dp[i][j]);
                }
            }
        }
        
        return Max*Max;
    }
};
