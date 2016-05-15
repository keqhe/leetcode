
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int len1 = s.length();
        int len2 = t.length();
        
        if (abs(len1 - len2) >= 2 || s == t)
            return false;
        for (int i = 0; i < min(len1, len2); i ++) {
            if (s[i] != t[i]) {
                if (s.length() == t.length())
                    return s.substr(i+1) == t.substr(i+1);
                else if (s.length()+1 == t.length())
                    return s.substr(i) == t.substr(i+1);
                else if (t.length()+1 == s.length())
                    return t.substr(i) == s.substr(i+1);
                else
                    return false;
            }
        }
        return true;
    }
};
