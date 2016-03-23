
class Solution {
public:
    void helper(vector<int> & cans, int target, int start, int count, vector<int> & inst, vector<vector<int>> & res) {
        if (target == 0 && count == 0) {
            res.push_back(inst);
            return;
        }
        else if (target < 0 || count < 0)// same as !(target > 0 && count > 0)
            return;
        for (int i = start; i < cans.size(); i++) {
            inst.push_back(cans[i]);
            helper(cans, target-cans[i], i+1, count-1, inst, res);
            inst.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates = {1,2,3,4,5,6,7,8,9};//c++ 11 is okay with this kind of initialization
        vector<vector<int>> res;
        vector<int> inst;
        
        helper(candidates, n, 0, k, inst, res);
        return res;
    }
};
