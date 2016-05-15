
class Solution {
public:
    void backtracking(vector<int> & candidates, int index, int sum, int target, vector<int>&path, vector<vector<int>> &res) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        if (sum > target)
            return;
        for (int i = index; i < candidates.size(); i ++) {
            //if (i > 0 && candidates[i] == candidates[i-1])//this is WRONG, think why
            if (i > index && candidates[i] == candidates[i-1])
                continue;//not need to get a brach from in this case;
            path.push_back(candidates[i]);
            backtracking(candidates, i+1, sum+candidates[i], target, path, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if (candidates.empty()) 
            return res;
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        backtracking(candidates, 0, 0, target, path, res);
        return res;
    }
};
