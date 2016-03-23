
class Solution {
public:
    //backtracking: https://en.wikipedia.org/wiki/Backtracking
    void backtracking(string digits, vector<string> dict, string tillnow, int level, vector<string> & res) {
        if (level == digits.size()) {
            res.push_back(tillnow);
            return;//CRITICAL
        }
        int num = digits[level] - '0';
        
        string letter = dict[num];
        //cout << "letter is " << letter << endl;
        for (int i = 0; i < letter.length(); i ++) {
            //backtracking(digits, dict, tillnow+letter[i], ++ level, res); THIS IS WRONG
            backtracking(digits, dict, tillnow+letter[i], level + 1, res);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        vector<string> dict = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        //do we really need this?, yes we do
        if (digits.length() == 0)
            return res;
        int level = 0;
        string tillnow;
        backtracking(digits, dict, tillnow, level, res);
        return res;
    }
};
