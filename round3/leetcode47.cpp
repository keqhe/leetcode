
class Solution {
public:
    //diferent from permutation I, now we have duplicates
    void backtracking(vector<int>&nums, vector<int>&path, vector<bool>&used, vector<vector<int>>&res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1]) //think why, take [1,2,2] and think
                continue;
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums, path, used, res);
                path.pop_back();
                used[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());

        vector<bool> used (nums.size(), false);
        vector<int> path;
        
        backtracking(nums, path, used, res);
        return res;
    }
};
