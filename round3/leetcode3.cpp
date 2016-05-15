
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;//char, the number of times a char appears
        int left = 0;
        int right = 0;
        int extra_counter = 0;//how many chars are extra (i.e., more than distinct)
        int maxLen = 0;
        while (right < s.length()) {
            if(m.find(s[right]) != m.end() && m[s[right]] > 0) {
                extra_counter ++;//1 extra char is there than "the distinct" requirement
            }
            m[s[right]] ++;
            right ++;
            while (extra_counter > 0) {
                if (m.find(s[left]) != m.end() && m[s[left]] > 1) {//note it is not > 0, think why
                    extra_counter --;
                }
                if (m.find(s[left]) != m.end() && m[s[left]] > 0)
                    m[s[left]] --;
                left ++;
            }
            maxLen = max(maxLen, right-left);
        }
        return maxLen;
    }
};
