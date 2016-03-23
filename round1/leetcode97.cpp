
class Solution {
public:
    //ref: http://www.geeksforgeeks.org/check-whether-a-given-string-is-an-interleaving-of-two-other-given-strings-set-2/
    //https://leetcode.com/discuss/60784/clean-c-dp-solution
    /*
    dp[i][j] means that if I have picked i-1 characters from s1, have picked j characters from s2, whether the ith character of s1(which is s1[i-1] ) is equal to (i+j)th character of s3, which is s3[i+j-1]. If yes, dp[i][j] = true;

    Similarly, dp[i][j] also means that if I have picked i characters from s1, have picked j-1 characters from s2, whether the j th character of s2(which is s2[j-1] ) is equal to (i+j)th character of s3, which is s3[i+j-1]. If yes, dp[i][j] = true;
    */
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length();
        int n = s2.length();
        int k = s3.length();
        
        if (k != m + n)
            return false;
        if (m == 0)
            return s2 == s3;
        if (n == 0)
            return s1 == s3;
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        //dp[i][j] == ture iff 
        cout << "debug..." << endl;
        for (int i = 0; i <= m; i ++) {
            for (int j = 0; j <= n; j ++) {
                if (i == 0 && j == 0)
                    dp[0][0] = true;
                else if (i == 0 && s2[j-1] == s3[j-1])// picked 0 chars from s1
                    dp[0][j] = dp[0][j-1];
                    
                else if (j == 0 && s1[i-1] == s3[i-1])//picked 0 chars from s2
                    dp[i][0] = dp[i-1][0];
                    
                else if (i > 0 && s1[i-1] == s3[i+j-1] && dp[i-1][j])
                    dp[i][j] = true;//pick from s1
                    
                else if (j > 0 && s2[j-1] == s3[i+j-1] && dp[i][j-1])
                    dp[i][j] = true;
            }
        }
        
        return dp[m][n];
    }
};
