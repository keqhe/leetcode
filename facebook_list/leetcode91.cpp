
class Solution {
public:
    //dp[i] denotes the number of ways to decode for s[0..i-1]
    //dp[i] = dp[i-2] + dp[i-1];
    //dp[0] = 1;
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        if (s.front() == '0')
            return 0;
        int len = s.length();
        vector<int> dp(len+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= len; i ++) {
            string last = s.substr(i-2, 2);
            int val = stoi(last);
            if (last[1] > '0' && val > 9 && val <= 26) {
                dp[i] = dp[i-1] + dp[i-2];
            }
            else if (last[1] > '0') {
                dp[i] = dp[i-1];
            }
            else if (val == 10 || val == 20)
                dp[i] = dp[i-2];
            else
                return 0;
        }
        return dp[len];
    }
};
