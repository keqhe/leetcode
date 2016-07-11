
class Solution {
public:
    void backtracking(int n, string path, int left, int right, vector<string>& res) {
        if (left == n && right == n) {
            res.push_back(path);
        }
        if (left < n)
            backtracking(n, path+'(', left+1, right, res);
        if (left > right)
            backtracking(n, path+')', left, right+1, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n <= 0)
            return res;
        backtracking(n, "", 0, 0, res);
        return res;
    }
};
