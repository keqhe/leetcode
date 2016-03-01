#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

class Solution {
public:
    //first thought is to use backtracking the get all potential partitions and find the one with minimal cuts, same idea as leetcode 131
    
    //ref: https://leetcode.com/discuss/76411/easiest-java-dp-solution-97-36%25
    //dp[i] denotes the minimal number of cuts needed for s[0...i]
    //dp[i] = min(dp[j-1]+1) for all 0<=j<=i, if s[j...i] is palindrome
    //pal[i][j] denotes whether substr s[i...j] is palindrome or not
    int minCut_ref(string s) {
        if (s.empty() || s.length() == 1)
            return 0;
        int len = s.length();
        vector<int> dp(len, 0);
        vector<vector<bool>> pal(len, vector<bool>(len, false));
        
        for (int i = 0; i < len; i ++) {
            int curr_min = numeric_limits<int>::max();
            for (int j = 0; j <= i; j ++) {
                //j+1 > i-1 includes two cases: 1)i==j and 2)j=i-1
                if (s[i] == s[j] && (j+1 > i-1 || pal[j+1][i-1])) {//i.e., s[j...i] is palindrome
                    pal[j][i] = true;
                    if (j == 0)
                        curr_min = 0;
                    else
                        curr_min = min(curr_min, dp[j-1]+1);
                    
                }
            }
            dp[i] = curr_min;
        }
        
        return dp[len-1];
    }
    
    //pal[i][j] denotes whether s[i..j] is palindorme
    int minCut(string s) {
        if (s.empty() || s.length() == 1)
            return 0;
        int len = s.length();
        vector<int> dp(len, 0);
        vector<vector<bool>> pal(len, vector<bool>(len, false));
        
        //first get pal matrix
        for (int i = 0; i < len; i ++)
            pal[i][i] = true;
        for (int i = 0; i+1 < len; i ++) {
            if (s[i] == s[i+1])
                pal[i][i+1] = true;
        }
        
        /*
        for (int i = 0; i < len; i ++) {
            for (int j = i+2; j < len; j ++) {
                //the following is WRONG!
                if (s[i] == s[j] && pal[i+1][j-1])//pal[i+1][j-1] has not been computed yet....
                    pal[i][j] = true;
            }
        }*/
        
        for (int i = 2; i < len; i ++) {
            for (int j = 0; j < i-1; j ++) {
                if (s[j] == s[i] && pal[j+1][i-1])//pal[j+1][i-1] must have been computed
                    pal[j][i] = true;
            }
        }
        
        //dp[i] denotes the minimal number of cuts for string s[0...i].
        //so dp[i] = min(dp[j-1]+1) for all 0 <= j <= i; if s[j...i] is palindrome
        
        for (int i = 0; i < len; i ++) {
            int curr_min = numeric_limits<int>::max();
            for (int j = 0; j <= i; j ++) {
                if (pal[j][i]) {
                    if (j == 0)
                        curr_min = 0;
                    else
                        curr_min = min(curr_min, dp[j-1]+1);
                }
            }
            dp[i] = curr_min;
        }
        
        return dp[len-1];
    }
};

int main() {
	class Solution sn;
	return 0;
}
