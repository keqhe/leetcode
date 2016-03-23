
class Solution {
public:
   
    void helper(int open, int close, string s, vector<string> & res) {
        if (open == 0 && close == 0)
            res.push_back(s);
        if (open > close)//meaning close parenthese is more than open parenthese
            return;
        if (open > 0)
            helper(open-1, close, s + "(", res);
        if (close >0)
            helper(open, close-1, s+ ")", res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        helper(n, n, s, res);
        return res;
    }
};
