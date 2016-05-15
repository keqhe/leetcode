
class Solution {
public:
    void backtracking(int n, int left, int right, string path, vector<string> & res) {
        if (path.length() == n+n) {
            res.push_back(path);
            return;
        }
        if (left < n) {
            backtracking(n, left+1, right, path+"(", res);
        }
        if (left > right) {//this is a key line
            backtracking(n, left, right+1, path+")", res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n == 0) {
            res.push_back("");
            return res;
        }
        backtracking(n, 0, 0, "", res);
        return res;
    }
};
