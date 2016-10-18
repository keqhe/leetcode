
class Solution {
public:
    //dp[i][j] denote the maximum square's ending at [i][j]'s length
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int max_len = 0;
        for (int j = 0; j < n; j ++) {
            dp[0][j] = matrix[0][j] == '1' ? 1 : 0;
            max_len = max(max_len, dp[0][j]);
        }
        
        for (int i = 0; i < m; i ++) {
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            max_len = max(max_len, dp[i][0]);
        }
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1])+1;
                }
                max_len = max(max_len, dp[i][j]);
            }
        }
        return max_len* max_len;
    }
};
