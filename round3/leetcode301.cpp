
class Solution {
public:
    //the facebook question
    //https://github.com/keqhe/leetcode/blob/master/round2/leetcode301.cpp
    //notice how dfs can also obtain optimal solution
    void dfs(string s, int index, int rmL, int rmR, int open, string path, unordered_set<string> & se) {
        if (index == s.length() && rmL == 0 && rmR == 0 && open == 0) {
            se.insert(path);
            return;
        }
        if (rmL < 0 || rmR < 0 || open < 0 || index >= s.length())
            return;
        if (s[index] == '(') {
            dfs(s, index+1, rmL-1, rmR, open, path, se);//do not take it
            dfs(s, index+1, rmL, rmR, open+1, path+"(", se);//take it
        }
        else if (s[index] == ')') {
            dfs(s, index+1, rmL, rmR-1, open, path, se);//do not take it
            if (open > 0)
                dfs(s, index+1, rmL, rmR, open-1, path+")", se);
        }
        else {
            dfs(s, index+1, rmL, rmR, open, path+s[index], se);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        
        int rmL = 0;//the number of "(" that need to be removed
        int rmR = 0;//the number of ")" that need to be removed
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
        unordered_set<string> se;
        dfs(s, 0, rmL, rmR, 0, "", se);
        for (auto x : se)
            res.push_back(x);
        return res;
    }
};
