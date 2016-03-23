
class Solution {
public:
    //the naive solution is to do binary search on each row, or each column, which is O(nlogn)
    //see, http://articles.leetcode.com/2010/10/searching-2d-sorted-matrix.html, 
    //O(m+n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if (m == 0)
            return false;
        int n = matrix[0].size();
        if (n == 0)
            return false;
        int row = 0;
        int column = n-1;
        while (row <= m-1 && column >= 0) {
            if (matrix[row][column] == target)
                return true;
            else if (matrix[row][column] < target)
                row ++;
            else
                column  --;
        }
        return false;
    }
};
