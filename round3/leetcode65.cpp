
class Solution {
public:
    bool isNumber(string s) {
        if (s.empty())
            return false;
        int i = 0;
        //check empty spaces
        for (; i < s.length(); i ++) {
            if (s[i] == ' ')
                continue;
            else
                break;
        }
        //check signs 
        if (s[i] == '+' || s[i] == '-') {
            i ++;
        }
        //check number part
        int c1 = 0;
        for (; i < s.length(); i ++) {
            if (isdigit(s[i])) {
                c1 ++;
                continue;
            }
            else 
                break;
        }
        if (s[i]  == '.') {
            i ++;
        }
        for (; i < s.length(); i ++) {
            if (isdigit(s[i])) {
                c1 ++;
                continue;
            }
                break;
        }
        if (c1 == 0)
            return false;
        //check E or e
        if (s[i] == 'E' || s[i] == 'e') {
            i ++;
            //check signs again
            if (s[i] == '+' || s[i] == '-') {
                i ++;
            }
            //check number part again
            int c2 = 0;
            for (; i < s.length(); i ++) {
                if (isdigit(s[i])) {
                    c2 ++;
                    continue;
                }
                else
                    break;
            }
            if (c2 == 0)
                return false;
        }
        
        //check tailing spaces
        for (; i < s.length(); i ++) {
            if (isspace(s[i]))
                continue;
            else
                break;
        }
        
        return i == s.length();
    }
};
