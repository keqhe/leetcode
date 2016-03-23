
class Solution {
public:
    //KMP algorithm
    //http://www.programcreek.com/2012/12/leetcode-implement-strstr-java/
    //http://www.cnblogs.com/yjiyjige/p/3263858.html
    //http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
    //i followed the cnblog one
    void getNext(vector<int> & next, string s) {
        //when j = 0, next[j] == -1, 
        //when j == 1, next[j] == 0;
        //when s[k] == s[j] --> next[++j] = ++k (note, next[j] = k)
        //when s[k] != s[j] --> k = next[k];
        int j = 0;
        int k = -1;
        next[0] = -1;
        while (j < s.length() - 1) {//j must be smaller than the largest index in string s
            if (k == -1 || s[k] == s[j])
                next[++j] = ++k;
            else
                k = next[k];
        }
    }
    int strStr(string haystack, string needle) {
        int sz1 = haystack.length();
        int sz2 = needle.length();
        
        if (sz2 == 0)
            return 0;
        if (sz1 != 0 && sz2 == 0)
            return -1;
        vector<int> next (sz2,0);
        getNext(next, needle);
        int i = 0; //i is the index of haystack
        int j = 0; //j is the index of needle
        while (i < sz1  && j < sz2) {
            if (j == -1 || haystack[i] == needle[j]) {
                i ++;
                j ++;
            }
            else {
                j = next[j];
            }
        }
        
        if (j == sz2) {//found the first occurence
            return i - j;
        }
        else
            return -1;
    }

    bool compareStr(string & s1, int start, string & s2) {
        int sz1 = s1.length();
        int sz2 = s2.length();
        if (sz1 - start < sz2)
            return false;
        int j = 0;
        for (int i = 0; i < sz2; i ++) {
            if (s2[i] != s1[start + j])
                return false;
            j ++;
        }
        return true;
    }
    //note: when needle is "", return 0
    //when haystack is "" and needle is not "", return -1;
    int strStr2(string haystack, string needle) {
        int sz1 = haystack.length();
        int sz2 = needle.length();
        if (sz2 == 0)
            return 0;
        
        for (int i = 0; i <= sz1 - sz2; i ++) {
            if (haystack[i] == needle[0]) {
                bool res = compareStr(haystack, i, needle);
                //cout << haystack[i] << ' ' << needle[0] << ' ' << i << ' ' << res << endl;
                if (res)
                    return i;
            }
        }
        return -1;
    }
};
