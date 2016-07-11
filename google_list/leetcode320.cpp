
class Solution {
public:
    void backtracking(string word, int index, int acc, string path, vector<string>& res) {
        if (index == word.length()) {
            if (acc > 0) {
                path += to_string(acc);
            }
            res.push_back(path);
        }
        if (index >= word.length())
            return;
        backtracking(word, index+1, 0, acc > 0 ? path+to_string(acc)+word[index]: path+word[index], res);
        backtracking(word, index+1, acc+1, path, res);
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        
        backtracking(word, 0, 0, "", res);
        return res;
    }
};
