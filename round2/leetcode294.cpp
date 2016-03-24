
class Solution {
public:
    bool helper(string s) {
        for (int i = 0; i + 1 < s.length(); i ++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string tmp = s;
                tmp[i] = '-';
                tmp[i+1] = '-';
                if (!helper(tmp))   
                    return true;
            }
        }
        return false;
    }
    bool canWin(string s) {
        return helper(s);
    }
};
