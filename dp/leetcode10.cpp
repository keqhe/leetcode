#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //ref: https://leetcode.com/discuss/43860/9-lines-16ms-c-dp-solutions-with-explanations
    //think about s="", p="a*" (* matches 0 preceding char), dp[0][2] = dp[0][0]
    //think about s="aa", p = "a*", dp[2][2]=dp[1][2]=dp[0][2]=dp[0][0]  
    //dp[i][j] denotes whether s[0..i-1] matches p[0...j-1]
    //when p[j-1] != '*', dp[i][j] == dp[i-1][j-1] && (s[i-1] == p[i-1] || p[i-1] = '.')
    //when p[j-1] == '*', dp[i][j] == dp[i][j-2] if * matches 0 preceding chars
    //when * matches at least 1 preceding chars, dp[i][j] = dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= m; i ++)
            dp[i][0] = false;
        /*
        for (int j = 1; j <= n; j ++)
            dp[0][j] = false; //this is WRONG, why? e.g., s="" and p = "a*";
        */
        for (int i = 0; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (p[j-1] != '*') {
                    dp[i][j] = (i > 0) && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1] == '.');
                }
                else {//p can not start with '*'
                    dp[i][j] = dp[i][j-2] || ((i > 0) && (s[i-1] == p[j-2] || p[j-2] == '.') &&
                                        dp[i-1][j]);
                }
            }
        }
        
        return dp[m][n];
    }
    //dp[i][j] denotes whether s[0..i-1] matches p[0...j-1]
    //when p[j-1] != '*', dp[i][j] = (i>0) && dp[i-1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.')
    //else dp[i][j] = dp[i][j-2] || (i>0) && (s[i-1] == p[j-2] || p[j-2]=='.') && dp[i-1][j]
    bool isMatch__(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        vector<vector<bool>> dp(2, vector<bool>(n+1, false));
        
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 && j == 0)
                    dp[0][0] = true;
                else if (j == 0)
                    dp[i&1][j] = false;
                
                else if (j > 0) {//not p can not start with *
                    if (p[j-1] != '*') {
                        dp[i&1][j] = (i>0) && dp[(i-1)&1][j-1] && (s[i-1]==p[j-1] || p[j-1]=='.');
                    }
                    else {
                        dp[i&1][j] = dp[i&1][j-2] || ((i>0) && (s[i-1]==p[j-2] || p[j-2]=='.') && dp[(i-1)&1][j]);
                    }
                }
            }
            
        }
        
        return dp[m&1][n];
    }
};

int main() {
	class Solution sn;
	return 0;
}
