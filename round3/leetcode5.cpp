
class Solution {
public:
    //the first thought is DP (which meets MLE), let dp[i][j] denote whether s[i..j] is palindrome or not
    //dp[i][i]=true
    //dp[i][i-1]=true
    /*if s[i] == s[j] &&dp[i+1][j-1]
    then dp[i][j] |= true
    */
    string dp(string s) {//just for exercise, the 2D array kills it
        if (s.length() < 2)
            return s;
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, false));
        int maxLen = 0;
        int maxBegin = -1;
        for (int i = 0; i < len; i ++) {
            dp[i][i] = true;
            if(maxLen < 1) {
                maxLen = 1;
                maxBegin = i;
            }
        }
        for (int i = 1; i < len; i ++)
            dp[i][i-1] = true;//e.g., "aa" dp[1][0]=true, sp dp[0][1] can be true
        
        //O(n^2) time complexity
        for (int l = 2; l <= len; l ++) {
            for (int i = 0; i+1 < len; i ++) {
                int j = i+l-1;
                if (j < len) {
                    if (s[i] == s[j] && dp[i+1][j-1]) {
                        dp[i][j] |= true;
                        if (maxLen < l) {
                            maxLen = l;
                            maxBegin = i;
                        }
                    }
                }
            }
        }
        return s.substr(maxBegin, maxLen);
    }
    bool isPal(string s, int l, int r) {
        if (l < 0)
            return false;
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l ++;
            r --;
        }
        return true;
    }
    //the time complexity is still O(n^2), but O(1) space
    string longestPalindrome(string s) {
        //return dp(s);
        if (s.length() < 2)
            return s;
        string res;
        int currLen = 0;
        for (int i = 0; i < s.length(); i ++) {
            if (isPal(s, i-currLen-1, i)) {
                res = s.substr(i-currLen-1, currLen+2);
                currLen += 2;
            }
            else if (isPal(s, i-currLen, i)) {
                res = s.substr(i-currLen, currLen+1);
                currLen += 1;
            }
        }
        return res;
    }
};
