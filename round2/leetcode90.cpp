
class Solution {
public:
    void backtracking(vector<int> & nums, int index, vector<int> & path, vector<vector<int>> & res) {
        for (int i = index; i < nums.size(); i ++) {
            if (i > index && nums[i] == nums[i-1])
                continue;
            path.push_back(nums[i]);
            res.push_back(path);
            backtracking(nums, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        res.push_back(path);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, path, res);
        return res;
    }
};
