
class Solution {
public:
    //well, this following works, it is not that clean...
    bool searchMatrix_not_clean(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int low = 0;
        int high = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        
        while (low <= high && left <= right) {
            if (matrix[low][right] == target || matrix[high][left] == target)
                return true;
            if (matrix[low][right] < target) {
                low ++;
            }
            else {
                right --;
            }
            
            if (matrix[high][left] < target) {
                left ++;
            }
            else {
                high --;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        //search from the top right, we can also start from bottom left
        int i = 0;
        int j = n-1;
        
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target) {
                j --;
            }
            else if (matrix[i][j] < target) {
                i ++;
            }
        }
        return false;
    }
};
