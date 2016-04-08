
class Solution {
public:
    //dp[i][j] denotes the length/width of the largest square ending at matrix[i][j] 
    /*if matrix[i][j] == 1
        dp[i][j] = min(dp[i-1][j-1],dp[i-1][j], dp[i][j-1])+1;
      else
        dp[i][j] = 0;
    */
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxLen = 0;
        for (int j = 0; j < n; j ++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            maxLen = max(maxLen, dp[0][j]);
        }
        for (int i = 1; i < m; i ++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            maxLen = max(maxLen, dp[i][0]);
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (matrix[i][j] == '1')
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                else 
                    dp[i][j] = 0;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen*maxLen;
    }
};
