
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        int len = needle.length();
        vector<int> KMP(len, 0);
        for (int i = 1, matched_pos = 0; i < len;) {
            if (needle[i] != needle[matched_pos]) {
                if (matched_pos > 0) {
                    matched_pos = KMP[matched_pos-1];
                }
                else {
                    i ++;
                }
            }
            else {
                KMP[i] = matched_pos + 1;
                i ++;
                matched_pos ++;
            }
        }
        for (int i = 0, matched_pos = 0; i < haystack.length();) {
            if (haystack[i] != needle[matched_pos]) {
                if (matched_pos > 0) {
                    matched_pos = KMP[matched_pos-1];
                }
                else {
                    i ++;
                }
            }
            else {
                if (matched_pos+1 == len) {
                    return i-len+1;
                }
                else {
                    i ++;
                    matched_pos ++;
                }
            }
        }
        return -1;
    }
};
