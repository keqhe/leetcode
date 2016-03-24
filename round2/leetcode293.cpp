
class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        vector<string> res;
        /*if (s.empty())
            return res;
        */
        //for (int i = 0; i < s.length() - 1; i ++) {//WRONG, because if s is empty
        for (int i = 0; i + 1 < s.length(); i ++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string tmp = s;
                tmp[i] = '-';
                tmp[i+1] = '-';
                res.push_back(tmp);
            }
            cout << "debug.." << endl;
        }
        return res;
    }
};
