
class Solution {
public:
    //add a char, delete a char, modify a char
    bool isOneEditDistance(string s, string t) {
        if (s.length() == t.length()) {
            for (int i = 0; i < s.length(); i ++) {
                if (s[i] != t[i]) {
                    return s.substr(i+1) == t.substr(i+1); 
                }
            }
            return false;
        }
        else if (s.length() + 1 == t.length()) {
            for (int i = 0; i < s.length(); i ++) {
                if (s[i] != t[i]) {
                    return s.substr(i) == t.substr(i+1);
                }
            }
            return true;
        }
        else if (t.length() + 1 == s.length())
            return isOneEditDistance(t, s);
        else
            return false;
    }
};
