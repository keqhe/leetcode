
class Solution {
public:
    void backtracking(vector<int> & nums, int k, int index, vector<int> & path, vector<vector<int>> & res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            backtracking(nums, k, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (n == 0 || k == 0)
            return res;
        vector<int> path;
        vector<int> nums;
        for (int i = 1; i <= n; i ++)
            nums.push_back(i);
        backtracking(nums, k, 0, path, res);
        return res;
    }
};
