
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;
        int row_up = 0;
        int row_down = matrix.size() - 1;
        int col_left = 0;
        int col_right = matrix[0].size() - 1;
        while (row_up < row_down && col_left < col_right) {
            //row up
            for (int i = col_left; i <= col_right; i ++) 
                res.push_back(matrix[row_up][i]);
            row_up ++;
            //right col
            for (int j = row_up; j <= row_down; j ++)
                res.push_back(matrix[j][col_right]);
            col_right --;
            //row down
            for (int i = col_right; i >= col_left; i --)
                res.push_back(matrix[row_down][i]);
            row_down --;
            //col left
            for (int j = row_down; j >= row_up; j --)
                res.push_back(matrix[j][col_left]);
            col_left ++;
        }
        //left one row, one col, or one row + one col
        if (row_up == row_down) {
            for (int i = col_left; i <= col_right; i ++)
                res.push_back(matrix[row_up][i]);
        }
        
        else if (col_left == col_right) {
            for (int j = row_up; j <= row_down; j ++)
                res.push_back(matrix[j][col_left]);
        }
        return res;
    }
};
