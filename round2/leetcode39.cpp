
class Solution {
public:
    void backtracking_1(vector<int> & candidates, int target, int sum, vector<int> & path, int index, vector<bool> & used, vector<vector<int>> & res) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        else if (sum > target)
            return;
        for (int i = index; i < candidates.size(); i ++) {
            if (i > index && (candidates[i] == candidates[i-1]) && used[i-1])
                continue;
            //cout << "push back : " << candidates[i] << endl;
            path.push_back(candidates[i]);
            used[i] = true;
            backtracking_1(candidates, target, sum+candidates[i], path, i, used, res);
            used[i] = false;
            path.pop_back();
            
        }
    }
    
    void backtracking(vector<int> & candidates, int target, int sum, vector<int> & path, int index, vector<vector<int>> & res) {
        if (sum == target) {
            res.push_back(path);
            return;
        }
        else if (sum > target)
            return;
        for (int i = index; i < candidates.size(); i ++) {
            if (i > index && (candidates[i] == candidates[i-1]))
                continue;
            //cout << "push back : " << candidates[i] << endl;
            path.push_back(candidates[i]);
            backtracking(candidates, target, sum+candidates[i], path, i, res);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        if (candidates.empty())
            return res;
        sort(candidates.begin(), candidates.end());
        vector<bool> used (candidates.size(), false);
        //backtracking_1(candidates, target, 0, path, 0, used, res);
        backtracking(candidates, target, 0, path, 0, res);
        return res;
    }
};
