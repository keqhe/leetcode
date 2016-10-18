
class Solution {
public:
    void bkt(unordered_map<char, string>&m, string digits, int pos, string path, vector<string>& res) {
        if (pos == digits.length()) {
            res.push_back(path);
        }
        string curr = m[digits[pos]];
        for (int i = 0; i < curr.length(); i ++) {
            bkt(m, digits, pos+1, path+curr[i], res);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};
        vector<string> res;
        unordered_map<char, string> m = {{'2', "abc"}, {'3', "def"},
        {'4', "ghi"},{'5', "jkl"},{'6', "mno"},{'7', "pqrs"},{'8', "tuv"}, {'9', "wxyz"}};
        bkt(m, digits, 0, "", res);
        return res;
    }
};
