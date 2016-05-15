
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int low = 0;
        int high = matrix.size()-1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] < target)
                low = mid + 1;
            else if (matrix[mid][0] > target)
                high = mid - 1;
        }
        //the correct row should be
        int row = high > 0 ? high : 0;//think why
        int left = 0;
        int right = matrix[0].size()-1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[row][mid] == target)
                return true;
            else if (matrix[row][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
