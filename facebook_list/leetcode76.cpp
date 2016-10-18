
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty())
            return "";
        if (s.empty())
            return "";
        unordered_map<char, int> um1;
        unordered_map<char, int> um2;
        int total = 0;
        for (auto c : t) {
            um1[c] ++;
        }
        int l = 0;
        int r = 0;
        int minLen = numeric_limits<int>::max();
        int minStart = -1;
        while (r < s.length()) {
            char c = s[r];
            if (um1.find(c) != um1.end() && 
                (um2.find(c) == um2.end() || um2[c] < um1[c])) {
                    total ++;
                }
            um2[c] ++;
            r ++;
            while (total >= t.length()) {
                if (r - l < minLen) {
                    minLen = r - l;
                    minStart = l;
                }
                char c = s[l];
                if (um1.find(c) != um1.end() && um2[c] <= um1[c]) {
                    total --;
                }
                um2[c] --;
                if (um2[c] == 0) {
                    um2.erase(c);
                }
                l ++;
            }
        }
        if (minLen == numeric_limits<int>::max())
            return "";
        else
            return s.substr(minStart, minLen);
    }
};
