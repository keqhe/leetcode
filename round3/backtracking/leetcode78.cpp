
class Solution {
public:
    void backtracking1(vector<int>& nums, int pos, vector<int> path, vector<vector<int>> & res) {
        if (pos == nums.size()) {
            res.push_back(path);
            return;
        }
        auto np = path;
        np.push_back(nums[pos]);
        backtracking1(nums, pos+1, np, res);//choose
        backtracking1(nums, pos+1, path, res);//not to choose
    }
    
    void backtracking(vector<int>& nums, int pos, vector<int>&path, vector<vector<int>> & res) {
        for (int i = pos; i < nums.size(); i ++) {
            path.push_back(nums[i]);//take the current 
            res.push_back(path);
            backtracking(nums, i+1, path, res);
            path.pop_back();//not take the current 
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty()) {
            vector<int> tmp;
            res.push_back(tmp);
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> path;
        res.push_back(path);//think why we need this
        backtracking(nums, 0, path, res);
        return res;
    }
};
