
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (s.empty() || k == 0)
            return 0;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        unordered_map<char, int> m;
        int distinct_cnt = 0;
        while (r < s.length()) {
            if (m.find(s[r]) == m.end()) {
                distinct_cnt ++;
            }
            m[s[r]] ++;
            r ++;
            while (distinct_cnt > k) {
                m[s[l]] --;
                if (m[s[l]] == 0) {
                    distinct_cnt --;
                    m.erase(s[l]);
                }
                l ++;
            }
            maxLen = max(maxLen, r-l);
        }
        return maxLen;
    }
};
