
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int> (n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;
        int curr = 1;
        while (top < bottom && left < right) {
            for (int j = left; j <= right; j ++)
                mat[top][j] = curr ++;
            top ++;
            for (int i = top; i <= bottom; i ++) 
                mat[i][right] = curr ++;
            right --;
            for (int j = right; j >= left; j --)
                mat[bottom][j] = curr ++;
            bottom --;
            for (int i = bottom; i >= top; i --)
                mat[i][left] = curr ++;
            left ++;
        }
        
        if (top == bottom) {
            for (int j = left; j <= right; j ++)
                mat[top][j] = curr ++;
        }
        else if (left == right) {
            for (int i = top; i <= bottom; i ++)
                mat[i][left] = curr ++;
        }
        return mat;
    }
};
