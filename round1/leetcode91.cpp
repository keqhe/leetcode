
class Solution {
public:
    //12 -> 2, 123, 
    //t[i] += t[i-1], t[i]+= t[i-2]
    bool isValid(string s) {
        int a = stoi(s);
        if (s[0] == '0')//think about "101"
            return false;
        if (a >= 1 && a <= 26)
            return true;
        else
            return false;
    }
    int numDecodings(string s) {
        if (s.length() == 0 || s[0] == '0')
            return 0;
            
        int len = s.length();
        len = len + 1;
        vector<int> t (len, 0);
    
        t[0] = 1;
        //think about "123", so t has a length of 4, t[0] must be 1 (why?)
        for (int i = 1; i <= s.length(); i ++) {
            if (isValid(s.substr(i-1,1)))
                t[i] += t[i-1];
            if (i-2 >= 0 && isValid(s.substr(i-2,2)))
                t[i] += t[i-2];
        }
        return t[s.length()];
    }
};
