
class Solution {
public:
    //how many are there? 2^n
    //ref: https://leetcode.com/discuss/75754/java-backtracking-solution
    //idea, for each char, we take it or we do not take it
    void backtracking(string word, int index, string path, int count, vector<string> & res) {
        if (index == word.length()) {
            if (count > 0)
                path += to_string(count);
            res.push_back(path);
            return;
        }
        backtracking(word, index+1, path, count+1, res);//we not take it
        backtracking(word, index+1, path+(count>0?to_string(count):"")+word[index], 0, res);
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        backtracking(word, 0, "", 0, res);
        return res;
    }
};
