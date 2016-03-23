
class Solution {
public:
    //O(n) manacher's algorithm, http://articles.leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
    //also this problem is palindromic substring, not subsequence, longest palindromic subsequence is a different problem
    //http://algorithms.tutorialhorizon.com/longest-palindromic-subsequence/
    string preProcess(string s) {//example, s="aba", after preProcess, it becomes "^#a#b#a#$"
        if (s == "")
            return "^$";
        string ret = "^";//^ is the first, $ is the last, # as the method to change odd/even lengths into odd lengths 
        for (int i = 0; i < s.length(); i ++) {
            ret += "#" + s.substr(i,1);
        }
        ret += "#$";
        return ret;
    }
    string longestPalindrome(string s) {
        if (s.length() == 0)
            return "";
        string T = preProcess(s);
        int n = T.length();
        int P[n] = {0};
        int C = 0;
        int R = 0;
        for (int i = 1; i < n-1; i ++) {
            int i_mirror = 2*C - i; //i_mirror = C - (i - C)
            P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
            //try to expand the palindromic substring centerred at i
            while (T[i+1+P[i]] == T[i-1-P[i]])
                P[i] ++;
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        int maxLen = 0;
        int center = 0;
        for (int i = 1; i < n-1; i ++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                center = i;
            }
        }
        //think about "aba" -> "^#a#b#a#$", P={0,0,1,0,3,0,1,0,0}
        return s.substr((center-1-maxLen)/2, maxLen);
    }
    
    //dynamic programming, basic idea; use p[i][j] to represent whether s[i..j] is palindromic or not
    //p[i-1][j+1] == true if s[i-1] == s[j+1] && p[i][j] == true;
    //base cases: 1) p[i][i] = true , 2) p[i][i+1] = (s[i] == s[i+1]);;; one for odd, one for even
    //O(n^2) time complexity and O(n^2) space complexity
    string longestPalindrome_nsquare(string s) {
        if (s.length() == 0 || s.length() == 1)
            return s;
        int len = s.length();
        vector<vector<bool>> p;
        p.resize(len, vector<bool>(len, false));
        
        int begin=0;
        int maxLen=1;
        for (int i = 0; i < len; i ++) {
            p[i][i] = true;
        }
        for (int i = 0; i < len - 1; i ++) {
            if (s[i] == s[i+1]) {
                p[i][i+1] = true;
                begin = i;
                maxLen = 2;
            }
        }
        for (int l = 3; l <= len; l ++) {
            for (int i = 0; i <= len-l; i ++) {
                int j = i + l - 1;
                //cout << l << ' ' << i << ' ' << j << endl;
                if (s[i] == s[j] && p[i+1][j-1] == true) {
                    p[i][j] = true;
                    begin = i;
                    maxLen = l;
                    //cout << begin <<' ' <<maxLen << endl;
                }
            }
        }
        return s.substr(begin, maxLen);
    }
};
