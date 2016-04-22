
class Solution {
public:
    //the array may contain duplicates
    void backtracking(vector<int>&nums, int pos, vector<int> &path, vector<vector<int>> & res) {
        for (int i = pos; i < nums.size(); i ++) {
            if (i > pos && nums[i] == nums[i-1])//note it is "i > pos" think why
                continue;//nums[i-1] == nums[i]
            path.push_back(nums[i]);
            res.push_back(path);
            backtracking(nums, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        vector<int> path;
        res.push_back(path);//empty set
        backtracking(nums, 0, path, res);
        return res;
    }
};
