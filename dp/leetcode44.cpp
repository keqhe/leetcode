#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    //dp[i][j] denotes whether s[0..i-1] matches p[0..j-1]
    //when p[j-1] != '*', dp[i][j] = (s[i-1]==p[j-1] || p[j-1]=='?') && dp[i-1][j-1]
    //when p[j-1] =='*', dp[i][j] = dp[i][j-1] || (dp[i-1][j]);
    bool isMatch_square(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true;
        
        for (int i = 1; i <= m; i ++)
            dp[i][0] = false;
            
        for (int i = 0; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (p[j-1] != '*')
                    dp[i][j] = (i > 0) && (s[i-1] == p[j-1] || p[j-1] == '?') && dp[i-1][j-1];
                else
                    dp[i][j] = dp[i][j-1] || (i > 0) && dp[i-1][j];
                    //dp[i][j-1] means when p[j-1] (*) matches 0 chars
                    //dp[i-1][j] means when p[j-1] (*) matches at least 1 char
                    //take s="aa" and p="a*" as an example
            }
        }
        
        return dp[m][n];
    }
    
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(2, vector<bool>(n+1, false));
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 && j == 0)
                    dp[0][0] = true;
                else if (i > 0 && j == 0)
                    dp[i&1][0] = false;
                else {
                    if (p[j-1] != '*')
                        dp[i&1][j] = (i > 0) && (s[i-1] == p[j-1] || p[j-1] == '?') && dp[(i-1)&1][j-1];
                    else
                        dp[i&1][j] = dp[i&1][j-1] || (i > 0) && dp[(i-1)&1][j];
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
