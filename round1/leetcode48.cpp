
class Solution {
public:
    //rotate layer by layer, 
    //key is : m[i][j] = m[n-1-j][i], where n is m's size
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)// this is a n*n 2D array
            return;
        int n = matrix.size();
        int left = 0; int right = matrix.size() - 1;
        while (left < right) {
            for (int i = left; i < right; i ++) {
                int tmp = matrix[left][i];
                matrix[left][i] = matrix[n-1-i][left];
                matrix[n-1-i][left] = matrix[n-1-left][n-1-i];
                matrix[n-1-left][n-1-i] = matrix[i][n-1-left];
                matrix[i][n-1-left] = tmp; //i.e., matrix[left][i] according to the rule
            }
            left ++;
            right --;
            //no need to maintain top, bottom because it is a n*n 2D array
        }
    }
};
