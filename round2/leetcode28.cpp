
class Solution {
public:
    //the naive solution is below, time complexisity is O(mn), m is the len of pattern, and n is th length of s
    bool check(string str, string s, int index) {
        for (int i = 0; i < str.length(); i ++) {
            if (str[i] != s[i+index])
                return false;
        }
        return true;
    }
    int strStr_naive(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;
        if (needle.empty())
            return 0;
        for (int i = 0; i + needle.length() <= haystack.length(); i ++) {
            if (needle.front() == haystack[i]) {
                if (check(needle, haystack, i))
                    return i;
            }
        }
        return -1;
    }
    //KMP
    //understand what does partial matching table, 
    //see ref http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
    //ref: https://leetcode.com/discuss/73278/kmp-in-c-explanation-included
    //KMP has time complexity of O(m+n)
    
    int strStr(string haystack, string needle) {
        if (haystack.length() < needle.length())
            return -1;
        if (needle.empty())
            return 0;
        int m = needle.length();
        int n = haystack.length();
        vector<int> kmpNext(m, 0);
        //compute the next table
        for (int i = 1, matched_pos = 0; i < m-1;) {
            if (needle[i] != needle[matched_pos]) {
                if (matched_pos > 0)
                    matched_pos = kmpNext[matched_pos-1];
                else
                    i ++;
            }
            else {
                kmpNext[i] = matched_pos + 1;
                i ++;
                matched_pos ++;
            }
        }
        
        for (int i = 0, matched_pos = 0; i < n;) {
            if (haystack[i] == needle[matched_pos]) {
                if (matched_pos == m - 1)
                    return i - m + 1;
                else {
                    i ++;
                    matched_pos ++;
                }
            }
            else {
                if (matched_pos > 0)
                    matched_pos = kmpNext[matched_pos-1];
                else
                    i ++;
            }
        }
        return -1;
    }
};
