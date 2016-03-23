
class Solution {
public:

    //below is one style of backtracking
    void helper(vector<int> nums, vector<int> tillnow, vector<vector<int>> & res) {
        if (nums.size() == 0) {
            res.push_back(tillnow);
            return;
        }
        
        
        for (int i = 0; i < nums.size(); i ++) {
           vector<int> c = nums; //must create a new var
           c.erase(c.begin() + i);
           vector<int> temp = tillnow;//here, it seems that in this style, you must create a new var
           
           temp.push_back(nums[i]);
           helper(c, temp, res);
        }
    }
    vector<vector<int>> permute_mine(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        vector<int> tillnow;
        helper(nums, tillnow, res);
        return res;
    }
    
    //another style
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-permutations-i-ii.html
    //the following two , both work
    //void helper2(vector<int> &nums, vector<int> per, vector<bool> used, vector<vector<int>> & res) {
    void helper2(vector<int> &nums, vector<int> & per, vector<bool>  &used, vector<vector<int>> & res) {
        if (per.size() == nums.size()) {
            res.push_back(per);
            return;
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            if (used[i]) continue;
            used[i] = true;
            per.push_back(nums[i]);
            helper2(nums, per, used, res);
            used[i] = false;
            per.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        vector<bool> used (nums.size(), false);
        vector<int> per;
        helper2(nums, per, used, res);
        return res;
    }
};
