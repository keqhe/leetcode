
class NumMatrix {
public:
    int m;
    int n;
    vector<vector<int>> copy;
    vector<vector<int>> BIT;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty())
            return;
        m = matrix.size();
        n = matrix[0].size();
        copy.resize(m, vector<int>(n, 0));
        BIT.resize(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int delta = val - copy[row][col];
        copy[row][col] = val;
        ++ row;
        ++ col;
        for (int i = row; i <= m; i += (i&-i)) {
            for (int j = col; j <= n; j += (j&-j)) {
                BIT[i][j] += delta;
            }
        }
    }

    int getSum(int row, int col) {
        int sum = 0;
        for (int i = row; i > 0; i -= (i&-i)) {
            for (int j = col; j > 0; j -= (j&-j)) {
                sum += BIT[i][j];
            }
        }
        return sum;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
       if (row1 > row2 || col1 > col2)
          return 0;
       int a = getSum(row1, col1);
       int b = getSum(row1, col2+1);
       int c = getSum(row2+1, col1);
       int d = getSum(row2+1, col2+1);
       
       return d-b-c+a;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
