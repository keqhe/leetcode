
//if it is immutable, dp works, //let dp[i][j] denote the range sum ending at matrix[i-1][j-1]

//ref: https://github.com/keqhe/leetcode/blob/master/binary_indexed_tree/leetcode308.cpp
//idea: 2D binary indexed tree
class NumMatrix {
public:
    int m = 0;
    int n = 0;;//m stands for number of rows, and n stands for number of cols
    vector<vector<int>> copy, BIT;//copy is a copy of the input 2D array, BIT is the binary indexed tree
    NumMatrix(vector<vector<int>> &matrix) {
        m = matrix.size();
        if (!matrix.empty())
            n = matrix[0].size();
        BIT.resize(m+1, vector<int>(n+1, 0));//initial 0s
        copy.resize(m+1, vector<int>(n+1, 0));//initial 0s
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                update(i, j, matrix[i][j]);
            }
        }
        cout << "debug m and n: " << m << " " << n << endl;
    }
    /*do not understand why the following does not work
    void update(int row, int col, int val) { //in update func, index row and col are in terms of matrix 
        ++ row;
        ++ col;
        cout << row << endl;
        int delta = val - copy[row][col];
        copy[row][col] = val;
        for (; row <= m; row += (row & -row)) {
            for (; col <= n; col += (col & -col)) {
                BIT[row][col] += delta;
            }
        }
    }*/
    void update(int row, int col, int val) { //in update func, index row and col are in terms of matrix 
        ++ row;
        ++ col;
        cout << row << endl;
        int delta = val - copy[row][col];
        copy[row][col] = val;
        for (int i = row; i <= m; i += (i & -i)) {
            for (int j = col; j <= n; j += (j & -j)) {
                BIT[i][j] += delta;
            }
        }
    }
    //getSum(row, col) returns the sum ending at matrxi[row-1][col-1]
    //i do not understand why following does not work
    /*int getSum(int row, int col) {//the getSum func, the index row and col are in terms of BIT
        if (row < 0 || row > m || col < 0 || col > n)//invalid input parameters
            return 0;
        int sum = 0;
        for (; row > 0; row -= (row & -row)) {
            for (; col > 0; col -= (col & -col)) {
                sum += BIT[row][col];
            }
        }
        cout << "debug getSum : " << sum << endl; 
        return sum;
    }*/
    int getSum(int row, int col) {
        if (row < 0 || row > m || col < 0 || col > n)//invalid input parameters
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
        if (row1 < 0 || row1 >= m || row2 < 0 || row2 >= m || row1 > row2 ||
            col1 < 0 || col2 >= n || col2 < 0 || col2 >= n || col1 > col2)
                return 0;//invalid input paramters
        cout << "debug sumRegion: " << endl;
        int a = getSum(row1, col1);//return sum ending at matrix[row1-1][col-1];
        int b = getSum(row2+1, col2+1);
        int c = getSum(row1, col2+1);//here need to think, why not getSum(row1, col2);
        int d = getSum(row2+1, col1);//the same as above
        return b-c-d+a;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
