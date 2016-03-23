
class Solution {
public:
    //The basic idea is to divide s1(s2) into two substrings with length k and len-k (where 1 < k < len) 
    //and check if the two substrings s1[0..k-1] and s1[k, len-1] are the scrambles of s2[0..k-1] and s2[k,len-1] or s2[len-k, len-1] and s2[0..len-k-1]
    //ref: https://leetcode.com/discuss/48917/solutions-recursion-recursion-cache-pruning-explanation
    //equation dp[len][i][j], this indicates whether s1[i...i+len-1] is scramble of s2[j...j+len-1]
    //for 1 < k < len,
    //dp[len][i][j] = dp[len][i][j] || (dp[k][i][j] && dp[len-k][i+k][j+k]);
    //dp[len][i][j] = dp[len][i][j] || (dp[k][i+len-k][j] && dp[len-k][i][j+k]);
    //when len = 2, "ab" is scamable of "ab": dp[1][0][0] && dp[1][1][1] == true;
    //"ab" is also scamble of "ba": dp[1][1][0] && dp[1][0][1] == true;
    bool isScramble(string s1, string s2) {
        
        int size1 = s1.length();
        int size2 = s2.length();
        if (size1 != size2)
            return false;
        if (size1 == 0)
            return true;
        if (size1 == 1)
            return s1 == s2;
        bool dp[size1+1][size1][size1];//initialized to false, i guess
        for (int i = 0; i < size1; i ++) {
            for (int j = 0; j < size1; j ++) 
                dp[1][i][j] = (s1[i] == s2[j]); 
        }
        
        for (int len = 2; len <= size1; len ++) {
            for (int i = 0; i < size1; i ++) {
                for (int j = 0; j < size1; j ++) {
                    dp[len][i][j] = false;
                    for (int k = 1; k < len; k ++) {
                        if (dp[len][i][j]) //no need to do further check
                            break;
                        dp[len][i][j] = dp[len][i][j] || (dp[k][i][j] && dp[len-k][i+k][j+k]);
                        dp[len][i][j] = dp[len][i][j] || (dp[k][i+len-k][j] && dp[len-k][i][j+k]);
                    }
                }
            }
        }
        
        return dp[size1][0][0];
    }
};
