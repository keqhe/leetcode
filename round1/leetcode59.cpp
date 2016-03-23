
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res;
        if (n == 0)
            return res;
        res.resize(n, vector<int> (n, 0)); //n ros and n columns, first n is row, second is columns
        
        int val = 0;
        int top = 0; int bottom = n - 1;
        int left = 0; int right = n - 1;
        while (top < bottom && left < right) {
            for (int i = left; i < right; i ++)
                res[top][i] = ++val;
            for (int i = top; i < bottom; i ++)
                res[i][right] = ++val;
            for (int i = right; i > left; i --)
                res[bottom][i] = ++val;
            for (int i = bottom; i > top; i --)
                res[i][left] = ++val;
            
            top ++;
            bottom --;
            left ++;
            right --;
        }
        
        //if n is even, the above is enough, if it is odd, one more data point
        if (top == bottom && left == right) {
            res[top][left] = ++val;
        }
        return res;
    }
};
