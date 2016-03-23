
class Solution {
public:
    //ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-combination-sum-i-ii.html
    void helper(vector<int> & can, int target, int start, vector<int> & inst, vector<vector<int>> & sol) {
        if (target == 0) {
            sol.push_back(inst);
            return;
        }
        else if (target < 0)
            return;
        for (int i = start; i < can.size(); i ++) {
            if (i > start && can[i] == can[i-1]) 
                continue;
            inst.push_back(can[i]);
            helper(can, target-can[i], i+1, inst, sol);
            inst.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        
        vector<int> inst;
        sort(candidates.begin(), candidates.end());
        helper(candidates, target, 0, inst, sol);
        return sol;
    }
};
