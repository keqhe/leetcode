
class Solution {
public:
    //think about [1, 1, 2]
    //[1, 1, 1, 2]
    void helper(vector<int> & nums, vector<int> & per, vector<bool> & used, vector<vector<int>> & res) {
        if (per.size() == nums.size()) {
            res.push_back(per);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i]) continue;
            //the following is critical
            //nums[i-1] has not been put into the solution but nums[i] == nums[i-1]
            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) //this is critical
                continue;
            used[i] = true;
            per.push_back(nums[i]);
            helper(nums, per, used, res);
            used[i] = false;
            per.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        vector<int> per;
        vector<bool> used (nums.size(), false);
        sort(nums.begin(), nums.end());//key
        helper(nums, per, used, res);
        return res;
    }
};
