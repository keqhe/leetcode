
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;
        int top = 0; int bottom = matrix.size() - 1;//how many rows
        int left = 0; int right = matrix[0].size() - 1;//how many columns
        
        while (top < bottom && left < right) {//this works for 2*2, 4*4 well
            for (int i = left; i < right; i ++)
                res.push_back(matrix[top][i]);
                
            for (int i = top; i < bottom; i ++)
                res.push_back(matrix[i][right]);
                
            for (int i = right; i > left; i --)
                res.push_back(matrix[bottom][i]);
                
            for (int i = bottom; i > top; i --)
                res.push_back(matrix[i][left]);
            
            top ++;
            bottom --;
            left ++;
            right --;
        }
        //cout << top <<' '<< bottom << endl;
        //cout << left << ' ' << right << endl;;;
        //cout << (top < bottom) << (left == right) << endl;
        if (bottom == top && left < right) {//matrix.size() is odd, but matrix[0].size is even, last row
            for (int i = left; i <= right; i ++) {
                res.push_back(matrix[bottom][i]);
            }
        }
        else if (top < bottom && left == right) {//matrix.size is even, but matrix[0].size is odd, last column
            for (int i = top; i <= bottom; i ++) {
                res.push_back(matrix[i][left]);
                cout << i << endl;
            }
        }
        else if (top == bottom && left == right){//last data point, both are odd
            res.push_back(matrix[top][left]);
        }
        
        return res;
    }
};
