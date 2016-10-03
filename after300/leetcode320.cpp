
class Solution {
public:
    void backtracking(string word, int index, string path, int num, vector<string>& res) {
        if (index == word.length()) {
            if (num == 0)
                res.push_back(path);
            else
                res.push_back(path+to_string(num));
            return;
        }
        //take this char
        if (num > 0) {
            auto next = path + to_string(num) + word[index];
            backtracking(word, index+1, next, 0, res);
        }
        else {
            auto next = path + word[index];
            backtracking(word, index+1, next, 0, res);
        }
        backtracking(word, index+1, path, num+1, res);
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        backtracking(word, 0, "", 0, res);
        return res;
    }
};
