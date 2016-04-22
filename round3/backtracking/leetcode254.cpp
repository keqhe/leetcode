
class Solution {
public:
    vector<int> factors(int n) {
        vector<int> res;
        for (int i = 2; i*i <= n; i ++) {
            if (n % i == 0) {
                res.push_back(i);
                if (i*i != n) //this is a big factor, think about n == 4
                    res.push_back(n/i);
            }
        }
        return res;
    }
    void backtracking(vector<int> &nums, int target, int multi, int idx, vector<int>&path, vector<vector<int>> & res) {
        if (multi == target) {
            res.push_back(path);
            return;
        }
        if (idx >= nums.size() || multi > target)
            return;
        
        for (int i = idx; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            //backtracking(nums, target, multi*nums[i], i, path, res);this is WRONG, think why
            backtracking(nums, target, multi*nums[i], i, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> nums = factors(n);
        if (nums.empty())
            return res;
        vector<int> path;
        backtracking(nums, n, 1, 0, path, res);
        return res;
    }
};
