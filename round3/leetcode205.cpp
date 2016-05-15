
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> m;
        for (int i = 0; i < s.length(); i ++) {
            char c1 = s[i];
            char c2 = t[i];
            if (m.find(c1) != m.end()) {
                if (m[c1] != c2)
                    return false;
            }
            else {
                m[c1] = c2;
            }
        }
        //m.clear
        m.clear();
        for (int i = 0; i < t.length(); i ++) {
            char c1 = t[i];
            char c2 = s[i];
            if (m.find(c1) != m.end()) {
                if (m[c1] != c2)
                    return false;
            }
            else {
                m[c1] = c2;
            }
        }
        return true;
    }
};
