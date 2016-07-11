
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
            return 0;
        unordered_map<char, int> m;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while (r < s.length()) {
            m[s[r]] ++;
            r ++;
            while (m.size() > 2) {
                m[s[l]] --;
                if (m[s[l]] == 0)
                    m.erase(s[l]);
                l ++;
            }
            maxLen = max(maxLen, r - l);
        }
        return maxLen;
    }
};
