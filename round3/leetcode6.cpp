
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        vector<string> tmp(numRows);
        int r = 0;
        int direction = true;//down is true, up is false
        for (int i = 0; i < s.length(); i ++) {
            if (direction) {//currently going down
                if (r == numRows-1) {
                    direction = false;
                    tmp[r].push_back(s[i]);
                    r --;
                }
                else {
                    tmp[r].push_back(s[i]);
                    r ++;
                }
            }
            else {//currently going up
                if (r == 0) {
                    direction = true;
                    tmp[r].push_back(s[i]);
                    r ++;
                }
                else {
                    tmp[r].push_back(s[i]);
                    r --;
                }
            }
        }
        string res;
        for (auto s : tmp)
            res += s;
        return res;
    }
};
