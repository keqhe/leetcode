
class Solution {
public:
    //naive solution, time complexity is O(MN) in worst case
    int strStr_naive(string haystack, string needle) {
        for (int i = 0; i+needle.length() <= haystack.length(); i ++) {//"abcde" "ab"
            if (haystack.substr(i, needle.length()) == needle)
                return i;
        }
        return -1;
    }
    //KMP, think about this example, pattern = "aaaaa" and s = "aaaabaaaac", we do not need to match each position based on the information provided by the pattern string itself
    //the partial match table based on the pattern string
    int strStr_ok(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;
        if (needle.empty())
            return 0;
        int m = haystack.length();
        int n = needle.length();
        vector<int> kmpNext(n, 0);
        //compute the KMP next table
        for (int i = 1, pos_matched = 0; i < n;) {// i + 1 < n, still works
            if (needle[i] != needle[pos_matched]) {
                if (pos_matched > 0) {
                    pos_matched = kmpNext[pos_matched-1];
                }
                else
                    i ++;
            }
            else {
                kmpNext[i] = pos_matched + 1;
                i ++;
                pos_matched ++;
            }
        }
        //string matching
        //for (int i = 0, pos_matched = 0; i < m; i ++) {//I common error i made
        for (int i = 0, pos_matched = 0; i < m; ) {
            if (haystack[i] != needle[pos_matched]) {
                if (pos_matched > 0)
                    pos_matched = kmpNext[pos_matched-1];
                else
                    i ++;
            }
            else {
                if (pos_matched+1 == n)
                    return i-n+1;
                else {
                    i ++;
                    pos_matched ++;
                }
            }
        }
        return -1;
    }
    //do it again
    int strStr(string haystack, string needle) {
        if (needle.empty())
            return 0;
        if (haystack.length() < needle.length())
            return -1;
        int m = haystack.length();
        int n = needle.length();
        vector<int> next(n, 0);
        
        //get next table
        for (int i = 1, matched_pos = 0; i < n; ) {
            if (needle[i] != needle[matched_pos]) {
                if (matched_pos > 0)
                    matched_pos = next[matched_pos-1];
                else
                    i ++;
            }
            else {
                next[i] = matched_pos + 1;
                i ++;
                matched_pos ++;
            }
        }
        //match needle against haystack
        for (int i = 0, matched_pos = 0; i < m; ) {
            if (haystack[i] == needle[matched_pos]) {
                if (matched_pos+1 == n) {
                    return i - n + 1;
                }
                else {
                    //next[i] = matched_pos + 1;
                    i ++;
                    matched_pos ++;
                }
            }
            else {
                if (matched_pos > 0)
                    matched_pos = next[matched_pos-1];
                else
                    i ++;
            }
        }
        return -1;
    }
};
