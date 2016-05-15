
class Solution {
public:
    bool isPal(string s) {
        int l = 0;
        int r = s.length()-1;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l ++;
            r --;
        }
        return true;
    }
    void backtracking(string s, int index, vector<string> &path, vector<vector<string>>&res) {
        if (index == s.length()) {
            res.push_back(path);
            return;
        }
        for (int i = index; i < s.length(); i ++) {
            string str = s.substr(index, i-index+1);
            if (isPal(str)) {
                path.push_back(str);
                backtracking(s, i+1, path, res);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if (s.empty())
            return res;
        vector<string> path;
        backtracking(s, 0, path, res);
        return res;
    }
};
