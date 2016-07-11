
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int top = 0;
        int bottom = m-1;
        int left = 0;
        int right = n-1;
        
        while (top <= bottom && left <= right) {
            if (matrix[top][right] == target || matrix[bottom][left] == target)
                return true;
            if (matrix[top][right] < target)
                top ++;
            else
                right --;
            if (matrix[bottom][left] < target)
                left ++;
            else
                bottom --;
        }
        return false;
    }
};
