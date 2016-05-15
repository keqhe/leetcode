
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty())
            return res;
        int m = matrix.size();
        int n = matrix[0].size();
        
        int rowT = 0;//row top
        int rowB = m-1;//row bottom
        int colL = 0;//col left
        int colR = n-1;//col right
        while (rowT < rowB && colL < colR) {
            for (int j = colL; j <= colR; j ++) {
                res.push_back(matrix[rowT][j]);
            }
            rowT ++;
            for (int i = rowT; i <= rowB; i ++) {
                res.push_back(matrix[i][colR]);
            }
            colR --;
            for (int j = colR; j >= colL; j --) {
                res.push_back(matrix[rowB][j]);
            }
            rowB --;
            for (int i = rowB; i >= rowT; i --) {
                res.push_back(matrix[i][colL]);
            }
            colL ++;
        }
        if (rowT == rowB && colL <= colR) {//test case [[2,3]]
            for (int j = colL; j <= colR; j ++)
                res.push_back(matrix[rowT][j]);
        }
        else if (rowT < rowB && colL == colR) {//test case [[2],[3]]
            for (int i = rowT; i <= rowB; i ++)
                res.push_back(matrix[i][colL]);
        }
        return res;
    }
};
