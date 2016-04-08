
class Solution {
public:
    //dp[i] denotes the number of decode ways of s[0..i-1]
    /*if both s[i] and s[i-1:i] make sense
        dp[i] = dp[i-1] + dp[i-2];
      else if s[i] makes sense
        dp[i] = dp[i-1];
      else if s[i-1:i] makes sense
        dp[i] = dp[i-2]
        */
    int numDecodings(string s) {
        if (s.empty())
            return 0;
        if (s[0] == '0')
            return 0;
        int len = s.length();
        vector<int> dp(len+1, 0);
        dp[0] = 1;//think why
        dp[1] = 1;//think why
        for (int i = 2; i <= len; i ++) {
            string str = s.substr(i-2, 2);
            if (str[1] > '0' && stoi(str) > 9 && stoi(str) <= 26)
                dp[i] = dp[i-1] + dp[i-2];
            else if (str[1] > '0')
                dp[i] = dp[i-1];
            else if (stoi(str) > 0 && stoi(str) <= 26)
                dp[i] = dp[i-2];
            else
                return 0;
        }
        return dp[len];
    }
};
