
class Solution {
public:
    //dp[i] denotes whether s[0..i-1] is breakable or not
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return false;
        int len = s.length();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i ++) {
            /*for (int j = 0; j < i; j ++) {
                string added = s.substr(j, i-j);
                if (wordDict.find(added) != wordDict.end() && dp[j])
                    dp[i] = true;
            }*/
            for (auto& w : wordDict) {
                int l = w.length();
                if (l <= i && s.substr(i-l, l) == w && dp[i-l])
                    dp[i] = true;
            }
        }
        return dp[len];
    }
};
