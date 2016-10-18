
class Solution {
public:
    void back(vector<int>& nums, int pos, vector<int>&path, vector<vector<int>>& res) {
        for (int i = pos; i < nums.size(); i ++) {
            if (i > pos && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            res.push_back(path);
            back(nums, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty())
            return {};
        sort(nums.begin(), nums.end());
        vector<int> path;
        vector<vector<int>> res;
        res.push_back(path);
        back(nums, 0, path, res);
        return res;
    }
};
