class Solution {
public:
    //the straitforward method, does not work for the test case with MANY zeros
    vector<vector<int>> multiply_tle(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.empty() || A[0].empty() || B.empty() || B[0].empty())
            return res;
        int m = A.size();
        int n = A[0].size();//n == B.size();
        int w = B[0].size();
        res.resize(m, vector<int>(w, 0));
        cout << "debug." << endl;
        //the resulting matrix should have m*w
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < w; j ++) {
                for (int k = 0; k < n; k ++) {
                    res[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        return res;
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.empty() || A[0].empty() || B.empty() || B[0].empty())
            return res;
        int m = A.size();
        int n = A[0].size();//n == B.size();
        int w = B[0].size();
        res.resize(m, vector<int>(w, 0));
        cout << "debug." << endl;
        //the resulting matrix should have m*w
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < w; j ++) {
                for (int k = 0; k < n; k ++) {
                    if (A[i][k] != 0 && B[k][j] != 0)
                        res[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        return res;
    }
};
