
class Solution {
public:
    //no duplicated numbers in this problem
    void backtracking(vector<int>& nums, vector<int> & path, vector<bool> & used, vector<vector<int>> & res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, path, used, res);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        vector<bool> used (nums.size(), false);
        vector<int> path;
        
        backtracking(nums, path, used, res);
        return res;
    }
};
