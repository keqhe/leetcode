
class NumMatrix {
public:
    //ref: https://leetcode.com/discuss/87626/lines-concise-easy-understand-solution-binary-indexed-tree
    //a bit amazing, binary indexed tree can be easily expanded into 2D...
    //a post about 2D BIT: https://leetcode.com/discuss/71169/java-2d-binary-indexed-tree-solution-clean-and-short-17ms
    /*
    One question about binary indexed tree. For 1D BIT, number 6's parent is 4, and number 4's parent is 2. Then in 2D BIT, what is the parent of number (6, 6)? and (6, 4)?

    I am thinking if (6, 6) has two parents, namely, (6, 4) and (4, 6), then it's no longer a tree. The shape is a graph.

    nice insight!! that's why the time complexity of updating is O(lgmlgn) - larger than that of tree which is O(lg(mn))==O(lgm+lgn). there are more cells we have to backtrack and update in each single call of update(x, y, i).

    in fact, the resulting (updating) graph is a DAG!
    */
    int m;
    int n;
    vector<vector<int>> orgin;// a copy of the orginal input matrix, only difference is it starts from index 1, not 0
    vector<vector<int>> BIT;
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        m = matrix.size();
        n = matrix[0].size();
        
        BIT.resize(m+1, vector<int>(n+1, 0));
        orgin.resize(m+1, vector<int>(n+1, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++)
                update(i, j, matrix[i][j]);
        }
    }

    void update(int r, int c, int val) {
        int delta = val - orgin[++r][++c];
        orgin[r][c] = val;
        for (int i = r; i <= m; i += (i&-i)) {//
            for (int j = c; j <= n; j += (j&-j)) {//
                BIT[i][j] += delta;
            }
        }
    }

    int getSum(int row, int col) {
        /*if (i <= 0 || i > m || j <= 0 || j > n)
            return 0;
        */
        int sum = 0;
        for (int i = row; i > 0; i -= (i&-i)) {
            for (int j = col; j > 0; j -= (j&-j)) {
                sum += BIT[i][j]; 
            }
        }
        return sum;
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 < 0 || row1 >= m || col1 < 0 || col1 >= n || 
            row2 < 0 || row2 >= m || col2 < 0 || col2 >= n)
            return 0;
        
        //the typical error i have... below
        /*
        int a = getSum(row1, col1);//range is the sum of [0][0] to [row1-1][col1-1]
        int b = getSum(row2+1, col2+1);
        return b-a;
        */
        return getSum(row2+1, col2+1) + getSum(row1, col1) - getSum(row2+1, col1) - getSum(row1, col2+1);
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.update(1, 1, 10);
// numMatrix.sumRegion(1, 2, 3, 4);
