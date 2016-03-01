#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //ref:https://leetcode.com/discuss/85424/simple-iterative-dp-java-solution-with-explanation
    //3D dp
    //dp[i][j][k] denotes whether s1[i..i+k-1] is a Scramble string of s2[j..j+k-1]
    //when k == 1, we just need to compare s1[i] == s2[j]
    //else, dp[i][j][k] 
    
    bool isScramble(string s1, string s2) {
        if (s1.length() != s2.length())
            return false;
        if (s1.empty())
            return true;
        int len = s1.length();
        vector< vector< vector<bool> > > dp(len, vector<vector<bool>>(len, vector<bool>(len+1, false)));
        
        /*the followin is WRONG! k should go first, think why?
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j < len; j ++) {
                for (int k = 1; i+k <= len && j+k <= len && k <= len; k ++) {
                    cout << "K is:" << k << endl;
                    if (k == 1)
                        dp[i][j][1] = (s1[i] == s2[j]);
                    else {
                        for (int l = 1; l < k && !dp[i][j][k]; l ++) {
                            //gr|eat
                            cout << "L is : " << l << endl;
                            cout << "dp[i][j][k] :" << dp[i][j][k] << endl;
                            cout << dp[i][j][l] << " " << dp[i+l][j+l][k-l] << " " << dp[i][j+k-l][l] << " " << dp[i+l][j][k-l] << endl;
                            cout << dp[0][0][1] << "," << dp[0][1][1] << "," << dp[1][0][1]<< "," << dp[1][1][1] << endl;
                            dp[i][j][k] = (dp[i][j][l] && dp[i+l][j+l][k-l]) ||
                                          (dp[i][j+k-l][l] && dp[i+l][j][k-l]);
                            cout << "dp[i][j][k] :" << dp[i][j][k] << endl;
                        }
                    }
                }
            }
        }
        */
        for (int k = 1; k <= len; k ++) {
            for (int i = 0; i + k <= len; i ++) {
                for (int j = 0; j + k <= len; j ++) {
                    if (k == 1)
                        dp[i][j][1] = (s1[i] == s2[j]);
                    else {
                        for (int l = 1; l < k && !dp[i][j][k]; l ++) {
                            //gr|eat
                            dp[i][j][k] = (dp[i][j][l] && dp[i+l][j+l][k-l]) ||
                                          (dp[i][j+k-l][l] && dp[i+l][j][k-l]);
                        }
                    }
                }
            }
        }
        /*
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j < len; j ++) {
                cout << dp[i][j][1] << " ";
            }
            cout << endl;
        } 
        cout << endl;
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j < len; j ++) {
                cout << dp[i][j][2] << " ";
            }
            cout << endl;
        } */
        return dp[0][0][len];
    }
};

int main() {
	class Solution sn;
	return 0;
}
