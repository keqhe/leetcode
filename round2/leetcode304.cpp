
class NumMatrix {
public:
    vector<vector<long>> mem;
    //mem[i][j] denotes the "squre sum" of area defined by [0][0] and [i-1][j-1]
    NumMatrix(vector<vector<int>> &matrix) {
        if (!matrix.empty() && !matrix[0].empty()) {
            int m = matrix.size();
            int n = matrix[0].size();
            mem.resize(m+1, vector<long>(n+1, 0));
            mem[1][1] = matrix[0][0];
            for(int i = 2; i <= m; i ++) {
                mem[i][1] = mem[i-1][1] + matrix[i-1][0];
            }
            for (int j = 2; j <= n; j ++) {
                mem[1][j] = mem[1][j-1] + matrix[0][j-1];
            }
            for (int i = 2; i <= m; i ++) {
                for (int j = 2; j <= n; j ++) {
                    mem[i][j] = mem[i-1][j] + mem[i][j-1] - mem[i-1][j-1] + matrix[i-1][j-1];
                }
            }
            
            for (int i = 0; i <= m; i ++) {
                for (int j = 0; j <= n; j ++) {
                    cout << mem[i][j] << " ";
                }
                cout << endl;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        if (mem.empty() || mem[0].empty())
            return 0;
        int m = mem.size();
        int n = mem[0].size();
        
        if (row1 < 0 || row1 >= m || row2 < 0 || row2 >= m ||
            col1 < 0 || col1 >= n || col2 < 0 || col2 >= n)
            return 0;
        long a = mem[row2+1][col2+1];
        long b = mem[row1][col2+1];//here error prone
        long c = mem[row2+1][col1];
        long d = mem[row1][col1];
        
        return a - b - c + d;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
