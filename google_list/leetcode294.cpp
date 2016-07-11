
class Solution {
public:
    //Time complexity is roughly O(n^n), n*n*n...
    bool canWin(string s) {
        for (int i = 0; i+1 < s.length(); i ++) {
            if (s[i] == '+' && s[i+1] == '+') {
                string str = s;
                str[i] = '-';
                str[i+1] = '-';
                if (!canWin(str))
                    return true;
            }
        }
        return false;
    }
};
