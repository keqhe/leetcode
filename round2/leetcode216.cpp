
class Solution {
public:
    void backtracking(int n, int k, int index, int sum, vector<int> & path, vector<vector<int>> & res) {
        if (path.size() == k) {
            if (sum == n)
                res.push_back(path);
            return;
        }
        
        for (int i = index; i <= 9; i ++) {
            path.push_back(i);
            backtracking(n, k, i+1, sum+i, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        backtracking(n, k, 1, 0, path, res);
        return res;
    }
};
