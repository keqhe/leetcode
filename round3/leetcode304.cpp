
class NumMatrix {
public:
    //let dp[i][j] denote the range sum ending at matrix[i-1][j-1]
    vector<vector<int>> dp;
    int row;
    int col;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        row = m;
        col = n;
        
        dp.resize(m+1, vector<int>(n+1, 0));
        for (int j = 1; j <= n; j ++) {
            dp[1][j] = dp[1][j-1] + matrix[0][j-1];
        }
        for (int i = 1; i <= m; i ++) {
            dp[i][1] = dp[i-1][1] + matrix[i-1][0];
        }
        for (int i = 2; i <= m; i ++) {
            for (int j = 2; j <= n; j ++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || row1 >= row || col1 < 0 || col1 >= col ||
            row2 < 0 || row2 >= row || col2 < 0 || col2 >= col ||
            row1 > row2 || col1 > col2)
            return 0;
        int a = dp[row2+1][col2+1];
        int b = dp[row1][col2+1];
        int c = dp[row2+1][col1];
        int d = dp[row1][col1];
        return a-b-c+d;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
