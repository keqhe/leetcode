
class Solution {
public:
    bool canWin(string s) {
        for (int i = 0; i+1 < s.length(); i ++) {
            string str = s;
            if (str[i] == '+' && str[i+1] == '+') {
                str[i] = '-';
                str[i+1] = '-';
                if (!canWin(str))
                    return true;
            }
        }
        return false;
    }
};
