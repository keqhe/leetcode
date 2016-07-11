
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        if (s.empty())
            return res;
        for (int i = 0; i+1 < s.length(); i ++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string str = s;
                str[i] = '-';
                str[i+1] = '-';
                res.push_back(str);
            }
        }
        return res;
    }
};
