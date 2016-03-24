
class Solution {
public:
    void backtracking(vector<int> & candidates, int target, int sum, vector<int> & path, int index, vector<vector<int>> & res) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        else if (sum > target)
            return;
        for (int i = index; i < candidates.size(); i ++) {
            if (i > index && candidates[i] == candidates[i-1])
                continue;
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum+candidates[i], path, i+1, res);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        if (candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, path, 0, res);
        return res;
            
    }
};
