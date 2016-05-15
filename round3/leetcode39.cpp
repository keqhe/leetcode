
class Solution {
public:
    void backtracking(vector<int> & candidates, int index, int sum, int target, vector<int> & path, vector<vector<int>> & res) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        if (sum > target)//because all numbers are positive
            return;
        for (int i = index; i < candidates.size(); i ++) {
            path.push_back(candidates[i]);//choose candidates[i]
            backtracking(candidates, i, sum+candidates[i], target, path, res);//the parameter i is key
            path.pop_back();//do not choose it
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtracking(candidates, 0, 0, target, path, res);
        return res;
    }
};
