
class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res;
        if (A.empty())
            return res;
        if (A[0].empty()) {
            res = vector<vector<int>> (A.size(), vector<int>());
            return res;
        }
        int m1 = A.size();
        int n1 = A[0].size();
        
        int n2 = B.size();
        int p2 = B[0].size();
        res.resize(m1, vector<int>(p2, 0));
        
        for (int i = 0; i < m1; i ++) {
            for (int k = 0; k < n1; k ++) {
                if (A[i][k] != 0) {
                    for (int j = 0; j < B[0].size(); j ++) {
                        res[i][j] += A[i][k]*B[k][j];
                    }
                }
                
            }
        }
        /*TLE
        for (int i = 0; i < m1; i ++) {
            for (int j = 0; j < p2; j ++) {
                for (int k = 0; k < n1; k ++) {
                    res[i][j] += A[i][k]* B[k][j];
                }
            }
        }*/
        return res;
    }
};
