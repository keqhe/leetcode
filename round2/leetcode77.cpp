
class Solution {
public:
    void backtracking(int n, int k, vector<int> & path, int index, vector<vector<int>> & res) {
        
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        
        for (int i = index; i < n; i ++) {
            path.push_back(i+1);
            backtracking(n, k, path, i+1, res);
            path.pop_back();
        }
    }
    
    void backtracking2(int n, int k, vector<int> & path, int index, vector<vector<int>> & res) {
        
        if (path.size() == k) {
            res.push_back(path);
            return;
        }
        
        path.push_back(index+1);
        backtracking(n, k, path, index+1, res);
        path.pop_back();
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(n, k, path, 0, res);
        return res;
    }
};
