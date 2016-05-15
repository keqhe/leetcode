
class Solution {
public:
    //nice solution at : https://leetcode.com/discuss/20240/share-my-dp-solution
    //so cool: https://leetcode.com/discuss/20240/share-my-dp-solution
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> left(n, 0);//the left bounds of left edge with 1 (inclusive)
        vector<int> right(n, n);//the right bound of right edge with 1 (exclusive)
        vector<int> height(n, 0);//the height of the rectangle
        
        int maxArea = 0;
        //row by row process 
        for (int i = 0; i < m; i ++) {
            int curr_left = 0;
            int curr_right = n;
            //the height of the potential rectangle
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == '1')
                    height[j] += 1;
                else
                    height[j] = 0;
            }
            
            //get left edge of the potential rectangle, must be processed from left to right, 
            //think why
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], curr_left);//the second left[j] is last row's
                else {
                    left[j] = 0;//why?
                    curr_left = j + 1;
                }
            
            }
            //get the right edge of the potential rectangle, must be processed from right to left
            for (int j = n-1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], curr_right);
                else {
                    right[j] = n;
                    curr_right = j;//note "curr_right = j" NOT "curr_right = j-1", think why
                }
            }
            
            for (int j = 0; j < n; j ++) {
                if (right[j] >= left[j])
                    maxArea = max(maxArea, (right[j]-left[j])*height[j]);
            }
        }
        return maxArea;
    }
};
