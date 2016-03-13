class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;
        unordered_map<char, char> m;
        int i = 0;
        int j = 0;
        for (; i < s.length(); i ++) {
            if (m.find(s[i]) == m.end()) {
                m[s[i]] = t[j];
                j ++;
            }
            else {
                if (m[s[i]] != t[j])
                    return false;
                else
                    j ++;
            }
        }
        //
        m.clear();
        i = 0;
        j = 0;
        for (; i < t.length(); i ++) {
            if (m.find(t[i]) == m.end()) {
                m[t[i]] = s[j];
                j ++;
            }
            else {
                if (m[t[i]] != s[j])
                    return false;
                else
                    j ++;
            }
        }
        return true;
    }
};
