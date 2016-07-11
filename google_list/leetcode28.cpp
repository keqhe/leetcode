
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.empty())
            return -1;
        int m = haystack.length();
        int n = needle.length();
        vector<int> KMPNext(n, 0);
        //the first one must be 0, MUST not start from index 0 here.
        for (int i = 1, matched_pos = 0; i < n;) {
            if (needle[i] != needle[matched_pos]) {
                if(matched_pos > 0) {
                    matched_pos = KMPNext[matched_pos-1];
                }
                else {
                    i ++;
                }
            }
            else {
                KMPNext[i] = matched_pos + 1;
                matched_pos ++;
                i ++;
            }
        }
        cout << "debug" << endl;
        for (int i = 0, matched_pos = 0; i < m;) {
            if (haystack[i] != needle[matched_pos]) {
                if (matched_pos > 0)
                    matched_pos = KMPNext[matched_pos-1];
                else
                    i ++;
            }
            else {
                if (matched_pos == n-1) {
                    return i-n+1;
                }
                matched_pos ++;
                i ++;
            }
        }
        return -1;
    }
};
