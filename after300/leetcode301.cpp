
class Solution {
public:
    void dfs(string s, int index, int rmL, int rmR, int open, string path, unordered_set<string> & us) {
        if (index == s.length() && rmL == 0 && rmR == 0 && open == 0) {
            us.insert(path);
            return;
        }
        if (index > s.length() || rmL < 0 || rmR < 0)
            return;
        if (s[index] == '(') {
            dfs(s, index+1, rmL-1, rmR, open, path, us);//do not take it
            dfs(s, index+1, rmL, rmR, open+1, path+'(', us);//take it
        }
        else if (s[index] == ')') {
            dfs(s, index+1, rmL, rmR-1, open, path, us);//do not take it
            if (open > 0) {
                dfs(s, index+1, rmL, rmR, open-1, path+')', us);//take it
            }
        }
        else {
            dfs(s, index+1, rmL, rmR, open, path+s[index], us);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        if (s.empty())
            return {""};
        int rmL = 0;
        int rmR = 0;
        for (auto c : s) {
            if (c == '(')
                rmL ++;
            else if (c == ')') {
                if (rmL > 0)
                    rmL --;
                else
                    rmR ++;
            }
        }
        unordered_set<string> us;
        dfs(s, 0, rmL, rmR, 0, "", us);
        for (auto x : us)
            res.push_back(x);
        return res;
    }
};
