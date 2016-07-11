
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty())
            return 0;
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        int total = 0;
        for (auto c : t) {
            m1[c] ++;
            total ++;
        }
        int l = 0;
        int r = 0;
        int minLen = numeric_limits<int>::max();
        int minIndex = -1;
        int curr = 0;
        while (r < s.length()) {
            if (m1.find(s[r]) != m1.end() && (m2.find(s[r]) == m2.end() || m2[s[r]] < m1[s[r]])) {
                curr ++;
            }
            m2[s[r]] ++;
            r ++;
            while (curr == total) {
                /*minLen = min(minLen, r-l);
                minIndex = l;*/ // WRONG
                if (r-l < minLen) {
                    minLen = r - l;
                    minIndex = l;
                }
                if (m1.find(s[l]) != m1.end() && m1[s[l]] >= m2[s[l]])
                    curr --;
                m2[s[l]] --;
                if (m2[s[l]] == 0)
                    m2.erase(s[l]);
                l ++;
            }
        }
        if (minLen == numeric_limits<int>::max())
            return "";
        return s.substr(minIndex, minLen);
    }
};
