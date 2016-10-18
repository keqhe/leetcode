
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.empty() || A[0].empty() || B.empty() || B[0].empty())
            return res;
        int m = A.size();
        int p = A[0].size();
        int n = B[0].size();
        res.resize(m, vector<int>(n, 0));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                for (int k = 0; k < p; k ++) {
                    if (A[i][k] == 0 || B[k][j] == 0)
                        continue;
                    else
                        res[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        return res;
    }
};
