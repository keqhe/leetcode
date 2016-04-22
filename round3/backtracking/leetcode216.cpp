
class Solution {
public:
    void backtracking(vector<int> & nums, int index, int k, int sum, int n, vector<int> & path, vector<vector<int>> & res) {
        if (sum == n) {
            if (path.size() == k) {
                res.push_back(path);
                return;
            }
        }
        if (sum >= n || path.size() >= k)
            return;
        for (int i = index; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            backtracking(nums, i+1, k, sum+nums[i], n, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if (k == 0 || k > n)
            return res;
        vector<int> nums;
        for (int i = 1; i <= 9; i ++)
            nums.push_back(i);
        vector<int> path;
        backtracking(nums, 0, k, 0, n, path, res);
        return res;
    }
};
