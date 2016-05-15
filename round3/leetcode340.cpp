
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.empty())
            return 0;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_map<char, int> m;
        int cnt = 0;
        while (r < s.length()) {
            if (m.find(s[r]) == m.end()) {
                cnt ++;
            }
            m[s[r]] ++;
            r ++;
            while (cnt > k) {
                if (m.find(s[l]) != m.end()) {
                    if (m[s[l]] == 1) {
                        cnt --;
                        m.erase(s[l]);
                    }
                    else if (m[s[l]] > 1) {
                        m[s[l]] --;
                    }
                }
                l ++;
            }
            maxLen = max(maxLen, r-l);
        }
        return maxLen;
    }
};
