#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //ref:https://leetcode.com/discuss/80292/my-o-n-time-c-solutions-stack-based-and-dp-based
    //similar to the fucking facebook interview the first official interview i took in Nov, 2015
    
    //1D dynamic programming
    //dp[i] denotes the longest valid parentheses ending at s[i-1]
    //dp[0] = 0;
    //if (s[i] == '(') dp[i+1] = 0;
    //else if (s[i] == ')')
    //think about (), i = 1
    //think about (()), i = 3
    int longestValidParentheses(string s) {
        if (s.empty())
            return 0;
        int len = s.length();
        vector<int> dp(len+1, 0);
        int maxLen = 0;
        for (int i = 0; i < len; i ++) {
            if (s[i] == '(')
                dp[i+1] = 0;
            else if (s[i] == ')') {
                int left = i- dp[i] - 1;
                if (left >= 0 && s[left] == '(') {
                    dp[i+1] = dp[i] + 2 + dp[left];
                    maxLen = max(maxLen, dp[i+1]);
                }
                else 
                    dp[i+1] = 0;
            }
        }
        return maxLen;
    }
    //dp[i][j] denotes the longest valid parenthenses for s[i...j],i.e., starting at i, ending at j
    //dp[i][i] = 0;
    //dp[i][i+1] = 2 if s[i] == '(' && s[i+1] == ')'
    //dp[i][j] = dp[i+1][j-1] + 2 if (s[i] == '(' && s[j] == ')') && dp[i+1][j-1] != 0
    //dp[i][j] = dp[i][j-2] + 2 if (s[j-1] == '(' && s[j] == ')') && dp[i][j-2] != 0
    
    //the following code causes memory limit exceed error for a very tough test case, but i think most likely it is correct
    int longestValidParentheses_2D_square(string s) {
        if (s.empty())
            return 0;
        int len = s.length();
        vector<vector<int>> dp(len, vector<int>(len, 0));
        int maxLen = 0;
        for (int i = 0; i+1 < len; i ++) {
            if (s[i] == '(' && s[i+1] == ')')
                dp[i][i+1] = 2;
                maxLen = max(maxLen, dp[i][i+1]);
        }
        
        for (int j = 2; j < len; j ++) {
            for (int i = j-2; i >= 0; i --) {
                if (s[i] == ')')
                    dp[i][j] = 0;
                else {
                    if (s[j] == '(')
                        dp[i][j] = 0;
                    else {
                        int opt1 = 0;
                        int opt2 = 0;
                        if (dp[i+1][j-1] != 0) //s[i] == '(' and s[j] == ')'
                            opt1 = dp[i+1][j-1] + 2;
                        if (s[j-1] == '(' && dp[i][j-2] != 0)
                            opt2 = dp[i][j-2] + 2;
                        dp[i][j] = max(opt1, opt2);
                        
                        maxLen = max(maxLen, dp[i][j]);
                    }
                }
            }
        }
        return maxLen;
    }
    
    
};

int main() {
	class Solution sn;
	return 0;
}
