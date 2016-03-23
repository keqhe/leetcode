
class Solution {
public:
    //Google interview question, how may abbrs are there in total? 2^n
    //to take it or not to take int
    void backtracking(string & word, string curr, int count, int index, vector<string> & res) {
        if (index == word.size()) {
            if (count > 0) curr += to_string(count);
            res.push_back(curr);
            return;
        }
        
        //for (int i = index; i < word.size(); i ++) { WHY DO not need it ?
        //take it
        //backtracking(word, curr+(count > 0 ? to_string(count): "") + word[index], count, index+1, res); //this is WRONG!!!!!
        backtracking(word, curr+(count > 0 ? to_string(count): "") + word[index], 0, index+1, res);
        //abbr it
        backtracking(word, curr, count+1, index+1, res);
        
    }
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        backtracking(word, "", 0, 0, res);
        return res;
    }
};
