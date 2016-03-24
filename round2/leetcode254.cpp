
class Solution {
public:
    vector<int> getCandidates(int n) {
        vector<int> res;
        for (int i = 2; i*i <= n; i ++) {
            if (n % i == 0) {
                res.push_back(i);
                if (i*i != n)
                    res.push_back(n/i);
            }
        }
        //cout << res.size() << endl;
        return res;
    }
    
    void backtracking(vector<int> & candidates, int n, int multi, vector<int> & path, int index, vector<vector<int>> & res) {
        if (multi == n) {
            res.push_back(path);
            return;
        }
        else if (multi > n)
            return;
        for (int i = index; i < candidates.size(); i ++) {
            //cout << "debug,, push_back..:" << candidates[i] << endl;
            path.push_back(candidates[i]);
            backtracking(candidates, n, multi*candidates[i], path, i, res);
            path.pop_back();
        }
    }
    vector<vector<int>> getFactors(int n) {
        vector<int> candidates = getCandidates(n);
        //cout << candidates[0] << endl;
        cout << candidates.empty() << endl;
        vector<int> path;
        vector<vector<int>> res;
        if (candidates.empty())
            return res;
        backtracking(candidates, n, 1, path, 0, res);
        return res;
    }
};
