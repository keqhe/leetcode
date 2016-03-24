
class Solution {
public:
    //ref: https://leetcode.com/discuss/80340/c-dfs-very-clean
    void backtracking(int index, string s, string path, vector<string> & res, unordered_map<char,string> & m) {
        if (index == s.length()) {
            res.push_back(path);
            return;
        }
        
        string str = m[s[index]];
        for (auto & c : str) {
            backtracking(index+1, s, path+c, res, m);
        }
        
    }
    vector<string> letterCombinations(string digits) {
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
        
        vector<string> res;
        if (digits.empty()) {
            //res.push_back("");
            return res;
        }
        backtracking(0, digits, "", res, m);
        return res;
    }
};
