
class Solution {
public:
    //the difficulty is all the corner cases
    //ref: https://leetcode.com/discuss/66609/8ms-easy-to-read-c-state-checking-solution
    bool isSpace(char c) {
        return c == ' ';
    }
    bool isEe(char c) {
        return c == 'E' || c == 'e';
    }
    bool isSign(char c) {
        return c == '+' || c == '-';
    }
    bool isNum (char c) {
        return c <= '9' && c >= '0';
    }
    bool isDot (char c) {
        return c == '.';
    }
    
    bool isNumber(string s) {
        if (s.empty())
            return false;
        int pos = 0;
        bool haveNum = false;
        //check all prefix spaces
        while (pos < s.length() && isSpace(s[pos]))
            pos ++;
        //check next whether are '+' or '-'
        while (pos < s.length() && isSign(s[pos]))
            pos ++;
        //check the digits before '.'
        while (pos < s.length() && isNum(s[pos])) {
            pos ++;
            haveNum = true;
        }
        //check the number is "."
        if (pos < s.length() && isDot(s[pos])) 
            pos ++;
        //check the digits after "."
        while (pos < s.length() && isNum(s[pos])) {
            pos ++;
            haveNum = true;
        }
        //check E or e
        if (pos < s.length() && haveNum && isEe(s[pos])) {
            haveNum = false;
            pos ++;
            while (pos < s.length() && isSign(s[pos]))
                pos ++;
        }
        //check the digits after 'E' or 'e'
        while (pos < s.length() && isNum(s[pos])) {
            pos ++;
            haveNum = true;
        }
        //check remaining spaces
        while (pos < s.length() && isSpace(s[pos]))
            pos ++;
        return haveNum && pos == s.length();
    }
};
