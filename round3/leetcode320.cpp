
class Solution {
public:
    //choose or not choose, 2^n 
    void backtracking(string word, int pos, string path, int cnt, vector<string> & res) {
        if (pos == word.length()) {
            if (cnt > 0)
                path += to_string(cnt);
            res.push_back(path);
            return;
        }
        //use this char
        backtracking(word, pos+1, cnt > 0 ? path+to_string(cnt)+string(1, word[pos]): path+string(1, word[pos]), 0, res);
        //do not use this char
        backtracking(word, pos+1, path, cnt+1, res);
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        
        backtracking(word, 0, "", 0, res);
        return res;
    }
};
