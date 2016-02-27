#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    //ref: https://leetcode.com/discuss/49719/dp-with-easy-understand-java-solution
    //dp[i] = dp[i-2] + dp[i-1], i here means length
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        if (s[0] == '0')
            return 0;
        
        vector<int> dp (s.length()+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= s.length(); i ++) {
            string str = s.substr(i-2, 2);

            if (stoi(str) <= 26 && stoi(str) > 9) {
                dp[i] += dp[i-2];
            }
            if (str[1] > '0') {
                dp[i] += dp[i-1]; 
            }
        }
        
        return dp[s.length()];
    }
};

int main() {
	class Solution sn;
	return 0;
}
