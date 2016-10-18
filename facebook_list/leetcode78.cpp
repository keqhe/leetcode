
class Solution {
public:
    void back(vector<int>& nums, int pos, vector<int> path, vector<vector<int>>& res) {
        if (pos == nums.size()) {
            res.push_back(path);
            return;
        }
        auto np = path;
        np.push_back(nums[pos]);
        back(nums, pos+1, path, res);
        back(nums, pos+1, np, res);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        back(nums, 0, path, res);
        return res;
    }
};
