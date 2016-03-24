
class Solution {
public:
    //sometimes we want to find the position that is just smaller than the target
    //a common requirement in leetcode binary search problems
    
    //well, this problem has a better solution
    //see ref: https://leetcode.com/discuss/83239/clean-c-implementation-with-detailed-complexity-analysis
    //key idea: top right coner can help us exclude a row or column
    //time complexity is O(m+n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int i = 0;
        int j = n - 1;
        while (i < m && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                j --;
            else 
                i ++;
        }
        return false;
        
    }
};
