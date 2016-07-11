
class Solution {
public:
    //backtracking
    void backtracking(string &digits, unordered_map<char, string> & book, int index, string &path, vector<string> & res) {
        if (index == digits.length()) {
            res.push_back(path);
            return;
        }
        string curr = book[digits[index]];
        for (int i = 0; i < curr.length(); i ++) {
            path.push_back(curr[i]);
            backtracking(digits, book, index+1, path, res);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty())
            return res;
        unordered_map<char, string> book;
        book['2'] = "abc";
        book['3'] = "def";
        book['4'] = "ghi";
        book['5'] = "jkl";
        book['6'] = "mno";
        book['7'] = "pqrs";
        book['8'] = "tuv";
        book['9'] = "wxyz";
        
        string path;
        backtracking(digits, book, 0, path, res);
        return res;
    }
};
