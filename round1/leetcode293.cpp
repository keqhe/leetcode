
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        if (s.length() <= 1)
            return vector<string>();
        vector<string> res;
        for (int i = 0; i < s.length()-1; i ++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string tmp = s;
                tmp[i] = '-';
                tmp[i+1] = '-';
                res.push_back(tmp);
            }
        }
        return res;
    }
};
