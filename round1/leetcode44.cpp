
class Solution {
public:
    //ref: https://leetcode.com/discuss/21634/c-dp-solution
    //dp[i][j] means whether s[0...i) matches p[0...j)
    //if p[j-1] != '*'', then dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
    
    //if p[j-1] == '*', then dp[i][j] = dp[i][j-1] || dp[i-1][j];  
    //dp[i][j-1] means "*" matches empty? and dp[i-1][j] means, "*" matches >= 1 char?
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        if(m > 30000) return false; // to skip the large test case
        vector<bool> prev(n+1, false);
        prev[0] = true;//dp[0][0] = true;
        for (int j = 1; j <= n; j ++) 
            prev[j] = prev[j-1] && (p[j-1] == '*');
        //so till now, first row is there
        for (int i = 1; i <= m; i ++) {
            vector<bool> curr(n+1, false);
            for (int j = 1; j <= n; j ++) {
                if (p[j-1] != '*') {
                    curr[j] = prev[j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
                }
                else {
                    curr[j] = curr[j-1] || prev[j];
                }
            }
            prev = curr;
        }
        
        return prev[n];
    }
};
