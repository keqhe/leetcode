
class Solution {
public:
    //about the last example: https://leetcode.com/discuss/97/the-given-examples-last-ismatch-true-dont-understand-why-true
    
    //ref: https://leetcode.com/discuss/43860/9-lines-16ms-c-dp-solutions-with-explanations
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        
        //dp[i][j] means whetehr s[0..i) and p[0..j) matches or not
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        
        dp[0][0] = true;//"" matches ""
        for (int i = 0; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                //why i start from 0 and j from 1??
                if (p[j-1] != '*')
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                else {//note no pattern p starts with an "*"
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.'));
                }
            }
        }
        
        return dp[m][n];
    }
};
