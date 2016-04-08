
class Solution {
public:
    //let dp[i] denote the length of the longest valid parenthese substring ending at s[i-1]
    //dp[i] = dp[i-1]
    int longestValidParentheses(string s) {
        if (s.length() < 2)
            return 0;
        int len = s.length();
        vector<int> dp(len+1, 0);
        int maxLen = 0;
        for (int i = 0; i < len; i ++) {
            if (s[i] == '(')
                dp[i+1] = 0;
            else if (s[i] == ')') {
                int start = i-dp[i]-1;//think about (())
                if (start >= 0 && s[start] == '(')
                    dp[i+1] = dp[start] + dp[i] + 2;
                else
                    dp[i+1] = 0;
                maxLen = max(maxLen, dp[i+1]);
            }
        }
        return maxLen;
    }
    //dp[i][j] the length of the longest valid parentheses substring s[i...j]
    //the is a good way to think about it, can not pass a tough test case though
    int longestValidParentheses_2D(string s) {
        if (s.length() < 2)
            return 0;
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int maxLen = 0;
        for (int i = 0; i+1 < len; i ++) {
            if (s[i] == '(' && s[i+1] == ')')
                dp[i][i+1] = 2;
                maxLen = max(maxLen, dp[i][i+1]);
        }
        
        for (int gap = 2; gap < len; gap ++) {
            for (int i = 0; i + gap < len; i ++) {
                int j = i + gap;
                int opt1 = 0;
                int opt2 = 0;
                if (s[i] == '(' && s[j] == ')' && dp[i+1][j-1] != 0)
                    opt1 = dp[i+1][j-1] + 2;
                if (s[j-1] == '(' && s[j] == ')' && dp[i][j-2] != 0)
                    opt2 = dp[i][j-2] + 2;
                dp[i][j] = max(opt1, opt2);
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        return maxLen;
    }
};
