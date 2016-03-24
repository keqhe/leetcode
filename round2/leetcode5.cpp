
class Solution {
public:
    //dp[i][j] denotes s[i..j] is a palindromic substring
    //dp[i][j] =  true iff s[i] == s[j] && dp[i+1][j-1] == true;
    //ref: https://leetcode.com/discuss/76819/clean-java-solution-using-dp-yet-the-time-complexity-is-o-n-2
    //dp version is TLE
    string longestPalindrome_TLE(string s) {
        int start = -1;
        int maxLen = 0;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        
        for (int i = 0; i < s.length(); i ++) {
            for (int j = i; j < s.length(); j ++) {
                if (s[i] == s[j] && (j-i <= 2 || dp[i+1][j-1]))
                    dp[i][j] = true;
                if (dp[i][j]) {
                    if (maxLen < j-i+1) {
                        start = i;
                        maxLen = j-i+1;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
    //here is another solution: https://leetcode.com/discuss/52814/ac-relatively-short-and-very-clear-java-solution
    bool isPal(string s, int left, int right) {
        if (left < 0)
            return false;
        while (left < right) {
            if (s[left] == s[right]) {
                left ++;
                right --;
            }
            else
                return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string res;
        int currLen = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (isPal(s, i-currLen-1, i)) {
                res = s.substr(i-currLen-1, currLen+2);
                currLen = currLen+2;
            }
            else if (isPal(s, i-currLen, i)) {
                res = s.substr(i-currLen, currLen+1);
                currLen = currLen+1;
            }
        }
        return res;
    }
};
