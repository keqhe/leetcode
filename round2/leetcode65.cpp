
class Solution {
public:
    //https://leetcode.com/discuss/88730/rainbow-concise-clearer-implementaiton-detailed-comments
    bool isNumber(string s) {
        if (s.empty())
            return false;
        int i = 0;
        int n = s.length();
        //skip spaces
        while (i < n && isspace(s[i]))
            i ++;
        //looking for signs + or -
        if (i < n && (s[i] == '+' || s[i] == '-'))
            i ++;
        //check numbers and points
        int c1 = 0;
        while (i < n && isdigit(s[i])) {
            i ++;
            c1 ++;
        }
        if (i < n && s[i] == '.')
            i ++;
        while (i < n && isdigit(s[i])) {
            i ++;
            c1 ++;
        }
        if (c1 == 0)
            return false;
        //check exp part
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            i ++;
            if (i < n && (s[i] == '+' || s[i] == '-'))
                i ++;
            int c2 = 0;
            while (i < n && isdigit(s[i])) {
                i ++;
                c2 ++;
            }
            if (c2 == 0)
                return false;
        }
        //skip spaces
        while (i < n && isspace(s[i]))
            i ++;
        return i == n;
    }
};
