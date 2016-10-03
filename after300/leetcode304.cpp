
class NumMatrix {
public:
    //sums[i][j] denotes the area sum ending at index [i-1][j-1].
    vector<vector<int>> sums;
    int m;
    int n;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        m = matrix.size();
        n = matrix[0].size();
        sums.resize(m+1, vector<int>(n+1, 0));
        for (int j = 0; j < n; j ++)
            sums[0][j+1] = sums[0][j] + matrix[0][j];
        for (int i = 0; i < m; i ++)
            sums[i+1][0] = sums[i][0] + matrix[i][0];
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || row1 >= m || col1 < 0 || col1 >= n ||
            row2 < 0 || row2 >= m || col2 < 0 || col2 >= n ||
            row1 > row2 || col1 > col2)
            return 0;
        int a = sums[row2+1][col2+1];
        int b = sums[row1][col2+1];
        int c = sums[row2+1][col1];
        int d = sums[row1][col1];
        
        return a-b-c+d;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
