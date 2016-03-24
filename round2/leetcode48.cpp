
class Solution {
public:
    /*[1,2
       3,4]
    */
    /*
      [3, 1]
      [4, 2]
    */
    /*[1 2 3
       4 5 6
       7 8 9]
    */
    /*[7 4 1
       8 5 2
       9 6 3]
    /* tmp = mat[i][j];
       mat[i][j] = mat[m-1-i][j] ///m[0][1] = m[2][]
       mat[m-1-i][j] = mat[m-1-i][n-1-j]
       mat[m-1-i][n-1-j] = mat[i][n-1-j]
       mat[i][n-1-j] = tmp;
       */
    /*
    tmp = m[i][j]
    m[i][j] = m[n-1-j][i];//m[0][0] = m[2][0], m[0][1] = m[1][0], m[1][0] = m[2][1], 
    m[n-1-j][i] = m[n-1-i][n-1-j];//
    m[n-1-i][n-1-j] = m[j][n-1-i]
    m[j][n-1-i] = m[i][j] = tmp;
    
    */   
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty())    
            return;
        int m = matrix.size();
        int n = matrix[0].size();
        int len = n;
        cout << m / 2 << endl;
        for (int i = 0; i < m/2; i ++) {
            for (int j = i; j + 1 < len; j ++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = tmp;
            }
            len --;
        }
    }
};

/*
[1  2  3  4]
[5  6  7  8]
[9 10 11 12]
[13 14 15 16]
*/
/*
[13 9 5 1]
[14 10 6 2]
[15 11 7 3]
[16 12 8 4]
*/
