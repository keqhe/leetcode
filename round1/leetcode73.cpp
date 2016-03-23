
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        helper1(matrix);
    }
    //use the first row and first column to record states, O(1) extra space, O(mn) time complexity
    void helper2(vector<vector<int>> & matrix) {
        int m = matrix.size();
        if (m < 1)
            return;
        int n = matrix[0].size();
        if (n < 1)
            return;
        bool firstrowZero = false;
        bool firstcolZero = false;
        
        for (int i = 0; i < m; i ++) {
            if (matrix[m][0] == 0)
                firstcolZero = true;
        }
        
        for (int i = 0; i < n; i ++) {
            if (matrix[0][i] == 0)
                firstrowZero = true;
        }
        //index from 1
        for (int i = 1; i < m; i ++) {
            for (int j = 1; j < n; j ++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        if (firstrowZero) {
            for (int i = 0; i < n; i ++)
                matrix[0][i] = 0;
        }
        
        if (firstcolZero) {
            for (int i = 0; i < m; i ++) {
                matrix[i][0] = 0;
            }
        }
    }
    //O(m+n) extra space, O(mn) time complexity
    void helper1(vector<vector<int>> & matrix) {
        int row = matrix.size();
        if (row < 1)
            return;
        int col = matrix[0].size();
        if (col < 1)
            return;
        vector<bool> ro (row, false);
        vector<bool> co (col, false);
        
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (matrix[i][j] == 0) {
                    ro[i] = true;
                    co[j] = true;
                }
            }
        }
        
        for (int i = 0; i < row; i ++) {
            for (int j = 0; j < col; j ++) {
                if (ro[i] || co[j])
                    matrix[i][j] = 0;
            }
        }
    }
};
