
class Solution {
public:
    //compare with: http://bangbingsyb.blogspot.com/2014/11/leetcode-subsets-i-ii.html
    //void helper1(vector<int> & nums, int start, vector<int>  inst, vector<vector<int>> & res) { , ALSO works
    void helper1(vector<int> & nums, int start, vector<int> &inst, vector<vector<int>> & res) {
        
        for (int i = start; i < nums.size(); i ++) {
            if (i > start && nums[i] == nums[i-1])
                continue;
            inst.push_back(nums[i]);
            res.push_back(inst);
            helper1(nums, i+1, inst, res);
            
            inst.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> inst;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        res.push_back(inst);
        helper1(nums, 0, inst, res);
        return res;
    }
    //below is my method
    void helper(vector<int> & nums, int start, int size, vector<int> & inst, vector<vector<int>> & res) {
        if (size == 0) {
            res.push_back(inst);
            return;
        }
        
        for (int i = start; i < nums.size(); i ++) {
            if (i > start && nums[i] == nums[i-1])
                continue;
            inst.push_back(nums[i]);
            helper(nums, i+1, size-1, inst, res);
            inst.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup_mine(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> e;
        res.push_back(e);
        
        sort(nums.begin(), nums.end());
        for (int size = 1; size <= nums.size(); size ++) {
            vector<int> inst;
            helper(nums, 0, size, inst, res);
        }
        return res;
    }
};
