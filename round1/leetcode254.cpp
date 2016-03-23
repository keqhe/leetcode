
class Solution {
public:
    void backtracking(int n, int start, int multi, vector<int> & curr, vector<vector<int>> & res) {
        if (multi == n && curr.size() > 1) {
            res.push_back(curr);
            return;
        }
        for (int i = start; multi*i <= n; i ++) {
            if (n % i == 0) {
                //cout << i << endl;
                curr.push_back(i);
                backtracking(n, i, multi*i, curr, res);
                curr.pop_back();
            }
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        if (n <= 1)
            return res;
        vector<int> curr;
        backtracking(n, 2, 1, curr, res);
        return res;
    }
};
