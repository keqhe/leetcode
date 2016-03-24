
class Solution {
public:
    //dp[i][j] denotes the number of distinct subsequences of t[0...i-1] in s[0...j-1]
    //dp[i][j] = dp[i][j-1] + dp[i-1][j-1] when t[i-1] == s[j-1]
    
    //first use 2D because it is easier to understand
    //ref of 2D: https://leetcode.com/discuss/72066/my-16ms-dp-solution-c
    //space complexity is O(n^2)
    int numDistinct_square_space(string s, string t) {
        if (t.length() > s.length())
            return 0;
        if (s == t)
            return 1;
        int m = t.length();
        int n = s.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int j = 0; j <= n; j ++)
            dp[0][j] = 1;
        for (int i = 1; i <= m; i ++)
            dp[i][0] = 0;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (t[i-1] == s[j-1]) {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        
        return dp[m][n];
    }
    
    //dp[i][j] denotes the number of distinct subsequences of t[0...i-1] in s[0...j-1]
    //dp[i][j] = dp[i][j-1] + dp[i-1][j-1] when t[i-1] == s[j-1]
    //dp[i][j] = dp[i][j-1] when t[i-1] != s[j-1]
    int numDistinct(string s, string t) {
        if (t.length() > s.length())
            return 0;
        if (s == t)
            return 1;
        int m = t.length();
        int n = s.length();
        vector<vector<int>> dp(2, vector<int>(n+1, 0));
        
        //note that dp[i][j] depends on dp[i-1][j-1] and dp[i][j-1]
        for (int i = 0; i <= m; i ++) {
            //for (int j = n; j >= 0; j --) {//this is WRONG, because it must be forwards direction
            for (int j = 0; j <= n; j ++) {
                if (i == 0)
                    dp[0][j] = 1; 
                else if (j == 0)
                    dp[i&1][j] = 0;
                else {
                    if (t[i-1] == s[j-1]) {
                        dp[i&1][j] = dp[i&1][j-1] + dp[(i-1)&1][j-1];
                    }
                    else
                        dp[i&1][j] = dp[i&1][j-1];
                }
            }
        }
        for (int i = 0; i <= 1; i ++) {
            for (int j = 0; j <= n; j ++) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[m&1][n];
    }
    
    //method 3, let dp[i][j] denotes the number of distinct subsequences of T[0..j] in S[0...i] (inclusive)
    //we have dp[*][0] = 1; dp[0][>=0] = 0;
    //dp[i][j] = dp[i-1][j] if T[i] != S[j]
    //or dp[i][j] = dp[i-1][j] + dp[i][j] if T[i] == S[j]
    //dp[i][j] depends on dp[i-1][j] and dp[i-1][j-1]
    //see ref: https://leetcode.com/discuss/83328/6-lines-java-solution-o-n-space-with-explanation
    
    //another way to think about this is:
    // let dp[i][j] denotes the number of distinct subsequences of T[0..j-1] in S[0...i-1] (inclusive)
    //dp[*][0] = 1; dp[0][>=1] = 0;
    //dp[i][j] = dp[i-1][j] if T[j-1] != S[i-1]
    //or dp[i][j] = dp[i-1][j] + dp[i-1][j-1] if T[j-1] == S[i-1]
    
    int numDistinct_method3(string s, string t) {
        if (t.length() > s.length())
            return 0;
        if (s == t)
            return 1;
        int m = t.length();
        int n = s.length();
        
        vector<int> dp(m+1, 0);
        for (int i = 0; i <= n; i ++) {
            for (int j = m; j >= 0; j --) {//must be backward, think why
                if (j == 0)
                    dp[j] = 1;
                else {
                    if (s[i-1] == t[j-1]) {
                        dp[j] = dp[j] + dp[j-1];
                    }
                }
            }
        }
        return dp[m];
    }
};
