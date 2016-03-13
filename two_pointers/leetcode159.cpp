class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int begin = 0;
        int end = 0;
        int counter = 0;//number of distinct chars used
        vector<int> m(256, 0);
        int maxLen = numeric_limits<int>::min();
        while (end < s.length()) {
            if (m[s[end]] == 0)
                counter ++;
            m[s[end]] ++;
            end ++;
            while (counter > 2) {
                if (m[s[begin]] == 1) {
                    counter --;
                }
                m[s[begin]]--;
                begin ++;
            }
            maxLen = max(maxLen, end-begin);
        }
        return maxLen == numeric_limits<int>::min() ? 0 : maxLen;
    }
};
