
class NumMatrix {
public:
    int m;
    int n;
    vector<vector<int>> copy;
    vector<vector<int>> BIT;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        m = matrix.size();
        n = matrix[0].size();
        BIT.resize(m+1, vector<int>(n+1, 0));
        copy = BIT;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        row ++;
        col ++;
        int delta = val - copy[row][col];
        copy[row][col] = val;
        for (int i = row; i <= m; i += (i&-i)) {
            for (int j = col; j <= n; j +=(j&-j)) {
                BIT[i][j] += delta;
            }
        }
    }

    int getSum (int row, int col) {
        if (row <= 0 || row > m || col <= 0 || col > n)
            return 0;
        int sum = 0;
        for (int i = row; i > 0; i -= (i&-i)) {
            for (int j = col; j > 0; j -= (j&-j)) {
                sum += BIT[i][j];
            }
        }
        return sum;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || row2 < 0 || row1 >= m || row2 >= m || row1 > row2 ||
            col1 < 0 || col2 < 0 || col1 >= n || col2 >= n || col1 > col2)
            return 0;
        int sum1 = getSum(row1, col1);
        int sum2 = getSum(row1, col2+1);
        int sum3 = getSum(row2+1, col1);
        int sum4 = getSum(row2+1, col2+1);
        return sum4 - sum2 - sum3 + sum1;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
