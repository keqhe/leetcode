
class Solution {
public:
    void backtracking(vector<int>& nums, vector<int> &path, vector<bool> &used, vector<vector<int>> & res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, path, used, res);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            vector<int> tmp;
            res.push_back(tmp);
            return res;
        }
        
        vector<int> path;
        vector<bool> used (nums.size(), false);
        backtracking(nums, path, used, res);
        return res;
    }
};
