
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return;
        int n = matrix.size();
        int l = 0;
        int r = n-1;
        int t = 0;
        int b = n-1;
        
        while (l < r && t < b) {
            for (int j = l; j < r; j ++) {
                int i = t;
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];//the basic rule of rotating
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
            l ++;
            r --;
            t ++;
            b --;
        }
    }
};
