
class Solution {
public:
    //ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-subsets-i-ii.html
    void backtracking(vector<int> & nums, int index, vector<int> & path, vector<vector<int>> & res) {
        for (int i = index; i < nums.size(); i ++) {
            path.push_back(nums[i]);
            res.push_back(path);
            backtracking(nums, i+1, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> res;
        res.push_back(path);
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, path, res);
        return res;
    }
};
