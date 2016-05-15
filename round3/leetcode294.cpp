
class Solution {
public:
    //this is recursion 
    bool canWin(string s) {
        for (int i = 0; i+1 < s.length(); i ++) {
            if (s[i] == '+' && s[i+1] == '+') {
                s[i] = '-';
                s[i+1] = '-';
                if (!canWin(s))
                    return true;
                s[i] = '+';
                s[i+1] = '+';
            }
        }
        return false;
    }
};
