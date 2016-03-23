
class Solution {
public:
    //e.g., [1, 2, 4, 5], key = 3
    int bsearch1(vector<vector<int>> & nums, int left, int right, int key) {
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid][0] == key)
                return mid;
            else if (nums[mid][0] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        //cout << "debug bsearch1" << endl;
        return right;
    }
    bool bsearch2(vector<int> & nums, int left, int right, int key) {
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == key)
                return true;
            else if (nums[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
            
        int row = bsearch1(matrix, 0, m-1, target);
        //cout << "row " << row << endl;
        if (row >= 0)
            return bsearch2(matrix[row], 0, n-1, target);
        else 
            return false;
    }
};
