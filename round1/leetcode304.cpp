
class NumMatrix {
public:
    //dp[i][j] is the sum from [0][0] to [i-1][j-1] (inclusive)
    //so given ([row1][col1], [row2][col2]), 
    //return dp[row2+1][col2+1] - dp[row2+1][col1+1] - dp[row1+1][col2+1] + dp[row1][col1]
    //ref: https://leetcode.com/discuss/71297/my-java-solution-only-used-6-ms
    //what if (row1 == row2 && col1 == col2), return 0, seems to be okay
    
    //for mutable, see: https://leetcode.com/discuss/69141/range-sum-query-2d-mutable-c-tree-array
    vector<vector<int>> precompute;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        precompute = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                precompute[i+1][j+1] = matrix[i][j] + precompute[i][j+1] + precompute[i+1][j] - precompute[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 > row2 || col1 > col2)
            return 0;
        ++row2;
        ++col2;
        if (row2 > precompute.size()-1)//row2 > m
            row2 = precompute.size() - 1;//row2 = m
        if (col2 > precompute[0].size()-1)
            col2 = precompute[0].size()-1;
        return precompute[row2][col2] - precompute[row2][col1] - precompute[row1][col2] + precompute[row1][col1];
            
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
