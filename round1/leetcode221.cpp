
class Solution {
public:
    //reference: https://leetcode.com/discuss/38489/easy-solution-with-detailed-explanations-8ms-time-and-space
    //key idea:
    /*
    P[0][j] = matrix[0][j] (topmost row);
    P[i][0] = matrix[i][0] (leftmost column);
    For i > 0 and j > 0: if matrix[i][j] = 0, P[i][j] = 0; if matrix[i][j] = 1, P[i][j] = min(P[i - 1][j], P[i][j - 1], P[i - 1][j - 1]) + 1
    */
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            cout << "empty.." << endl;
            return 0;
        }
            
        int m = matrix.size();//rows
        int n = matrix[0].size(); //columns
        vector<vector<int>> dp(m, vector<int> (n , 0));
        int maxsize = 0;
        for (int i = 0; i < n; i ++) {
            dp[0][i] = matrix[0][i] - '0';
            maxsize = max(maxsize, dp[0][i]);
        }
        
        for (int i = 0; i < m; i ++) {
            dp[i][0] = matrix[i][0] - '0';
            maxsize = max(maxsize, dp[i][0]);
        }
        
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else if (matrix[i][j] == '1')
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                maxsize = max(maxsize, dp[i][j]);
            }
        }
        return maxsize*maxsize;
        
    }
};
