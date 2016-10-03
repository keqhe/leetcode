
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> m;
        int count = 0;
        int l = 0;
        int r = 0;
        int maxLen = 0;
        while (r < s.length()) {
            if (m.find(s[r]) == m.end()) {
                count ++;
            }
            m[s[r]] ++;
            r ++;
            while (count > k) {
               m[s[l]] --;
               if (m[s[l]] == 0) {
                   m.erase(s[l]);
                   count --;
               }
               l ++;
            }
            maxLen = max(maxLen, r - l);
        }
        return maxLen;
    }
};
