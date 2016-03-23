
class Solution {
public:
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-combination-sum-i-ii.html
    void helper(vector<int> & cand, int start, int target, vector<int> & inst, vector<vector<int>> & sol) {
        if (target == 0) {
            sol.push_back(inst);
            return;
        }
        else if (target < 0)
            return;
        
        for (int i = start; i < cand.size(); i ++) {//i = start, why? 不回头扫，在扫描candidates[i]时，对candidate[i: n-1]递归查找target-candidates[i]。
            if (i > start && cand[i] == cand[i-1]) continue; //每层扫描的时候跳过重复的candidates。
            
            int curr = cand[i];
            inst.push_back(curr);
            helper(cand, i, target-curr, inst, sol);
            inst.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> sol;
        vector<int> inst;
        sort(candidates.begin(), candidates.end());
        helper(candidates, 0, target, inst, sol);
        
        return sol;
    }
};
