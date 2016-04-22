
class Solution {
public:
    void backtracking(string digits, unordered_map<char, string>&m, string path, vector<string>& res) {
        if (path.length() == digits.length()) {
            res.push_back(path);
            return;
        }
        int index = path.length();
        char c = digits[index];
        string str = m[c];
        for (int i = 0; i < str.length(); i ++) {
            backtracking(digits, m, path+str[i], res);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;
        unordered_map<char, string> m;
        m['0'] = " ";
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";
        
        backtracking(digits, m, "", res);
        return res;
    }
};
