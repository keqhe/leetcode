
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s == t)
            return false;
        if (abs((int)s.length()-(int)t.length()) >= 2)
            return false;
        for (int i = 0; i < min((int)s.length(), (int)t.length()); i ++) {
            if (s[i] == t[i])
                continue;
            else {
                if (s.length() == t.length())
                    return s.substr(i+1) == t.substr(i+1);
                else if (s.length() == t.length()+1) 
                    return s.substr(i+1) == t.substr(i);
                else if (s.length()+1 == t.length())
                    return s.substr(i) == t.substr(i+1);
                else
                    return false;
            }
        }
        return true;
    }
};
