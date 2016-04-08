
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l = 0;
        int r = 0;
        unordered_map<char, int> m;//char, the number of times a char appeared
        int counter = 0;//number of distinct chars
        int maxLen = 0;
        while (r < s.length()) {
            if (m.find(s[r]) == m.end()) {
                counter ++;
            }
            m[s[r]] ++;
            r ++;
            while (counter > 2) {
                if (m.find(s[l]) != m.end()) {//i think this must be satisfied
                    if (m[s[l]] == 1) {
                        counter --;
                        m.erase(s[l]);//erase char from the hash table
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
