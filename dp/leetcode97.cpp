#include<iostream>
#include<string>
#include<vector>

using namespace std;


class Solution {
public:
    //dp[i][j] denotes whether s3[0...i+j-1] is an intervealing string of s1[0...i-1] and s2[0..j-1]
    //when i == 0, dp[0][j] is true if s3[0..j-1] == s2[0..j-1], else false
    //when j == 0, dp[i][0] is true if s3[0..i-1] == s1[0..i-1], else false;
    //dp[i][j] |= dp[i-1][j] when s3[i+j-1] == s1[i-1] (note NOT s3[i+j-1] == s1[i], why?)
    //dp[i][j] |= dp[i][j-1] when s3[i+j-1] == s2[j-1] (note NOT s3[i+j-1] == s2[j], why?)
    bool isInterleave_squareSpace(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int len1 = s1.length();
        int len2 = s2.length();
        cout << "debug" << endl;
        vector<vector<bool>> dp(len1+1, vector<bool>(len2+1, false));
        dp[0][0] = true;
        /*
        for (int j = 1; j <= len2; j ++) {
            dp[0][j] = (s3[j-1] == s2[j-1]) && dp[0][j-1];
        }
        
        for (int i = 1; i <= len1; i ++) {
            dp[i][0] = (s3[i-1] == s1[i-1]) && dp[i-1][0];
        }
        */
        
        for (int j = 1; j <= len2; j ++) {
            if (s3[j-1] == s2[j-1])
                dp[0][j] = true;
            else
                break;
        }
        
        for (int i = 1; i <= len1; i ++) {
            if (s3[i-1] == s1[i-1])
                dp[i][0] = true;
            else
                break;
        }
        for (int i = 1; i <= len1; i ++) {
            for (int j = 1; j <= len2; j ++) {
                bool opt1 = false;
                bool opt2 = false;
                if (s3[i+j-1] == s1[i-1])
                    opt1 = dp[i-1][j];
                if (s3[i+j-1] == s2[j-1])
                    opt2 = dp[i][j-1];
                dp[i][j] = opt1 | opt2;
                /*
                dp[i][j] = (s3[i+j-1] == s1[i-1] && dp[i-1][j]) ||
                           (s3[i+j-1] == s2[j-1] && dp[i][j-1]);
                */
            }
        }
        /*
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++)
                cout << dp[i][j] << " ";
            cout << endl;
        }*/
        return dp[len1][len2];
    }
    
    //let us think how to reduce the space complexity to O(n), recall that
    ////dp[i][j] denotes whether s3[0...i+j-1] is an intervealing string of s1[0...i-1] and s2[0..j-1]
    //when i == 0, dp[0][j] is true if s3[0..j-1] == s2[0..j-1], else false
    //when j == 0, dp[i][0] is true if s3[0..i-1] == s1[0..i-1], else false;
    //dp[i][j] |= dp[i-1][j] when s3[i+j-1] == s1[i-1] (note NOT s3[i+j-1] == s1[i], why?)
    //dp[i][j] |= dp[i][j-1] when s3[i+j-1] == s2[j-1] (note NOT s3[i+j-1] == s2[j], why?)
    //dp[i][j] depends on dp[i-1][j] and dp[i][j-1]
    
    //the following method just need 2 rows so it is a easier way to reduce space complexity to O(n)
    bool isInterleave_n_method1(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int len1 = s1.length();
        int len2 = s2.length();
        vector<vector<bool>> dp(2, vector<bool>(len2+1, false));//the 2 row method
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                if (i == 0 && j == 0)
                    dp[0][0] = true;
                else if (i == 0) {
                    dp[0][j] = dp[0][j-1] && (s3[j-1] == s2[j-1]);
                }
                else if (j == 0) {
                    dp[i&1][0] = dp[(i-1)&1][0] && (s3[i-1] == s1[i-1]);
                }
                else {
                    dp[i&1][j] = (s3[i+j-1] == s2[j-1] && dp[i&1][j-1]) ||
                                (s3[i+j-1] == s1[i-1] && dp[(i-1)&1][j]);
                }
            }
        }
        
        return dp[len1&1][len2];
    }
    
    //now let's explore whether there is a better way to implement using O(n) space
    //recall that dp[i][j] denotes whether s3[0...i+j-1] is an intervealing string of s1[0...i-1] and s2[0..j-1]
    //when i == 0, dp[0][j] is true if s3[0..j-1] == s2[0..j-1], else false
    //when j == 0, dp[i][0] is true if s3[0..i-1] == s1[0..i-1], else false;
    //dp[i][j] |= dp[i-1][j] when s3[i+j-1] == s1[i-1] (note NOT s3[i+j-1] == s1[i], why?)
    //dp[i][j] |= dp[i][j-1] when s3[i+j-1] == s2[j-1] (note NOT s3[i+j-1] == s2[j], why?)
    //dp[i][j] depends on dp[i-1][j] and dp[i][j-1]
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.length() + s2.length() != s3.length())
            return false;
        int len1 = s1.length();
        int len2 = s2.length();
        vector<int> dp(len2+1, false);
        
        for (int i = 0; i <= len1; i ++) {
            for (int j = 0; j <= len2; j ++) {
                if (i == 0 && j == 0)
                    dp[0] = true;
                else if (i == 0) {
                    dp[j] = dp[j-1] && (s3[i+j-1] == s2[j-1]);
                }
                else if (j == 0) {
                    dp[0] = (s3.substr(0, i) == s1.substr(0, i));
                }
                else {
                    dp[j] = (s3[i+j-1] == s1[i-1] && dp[j]) ||
                            (s3[i+j-1] == s2[j-1] && dp[j-1]);
                }
            }
        }
        
        return dp[len2];
    }
    
};

int main() {
	class Solution sn;
	return 0;
}
