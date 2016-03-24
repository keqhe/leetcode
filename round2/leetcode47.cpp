
class Solution {
public:
    //compared with permutation problem, need to consider how to avoid duplicates
    //see ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-permutations-i-ii.html
    void backtracking(vector<int> & nums, vector<bool> & used, vector<int> &path, vector<vector<int>> & res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i])
                continue;
            if (i > 0 && nums[i] == nums[i-1] && used[i-1])
                continue;
            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used, path, res);
            used[i] = false;
            path.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            vector<int> tmp;
            res.push_back(tmp);
        }
       sort(nums.begin(), nums.end());
       vector<int> path;
       vector<bool> used(nums.size(), false);
       backtracking(nums, used, path, res);
       return res;
    }
};
