
class Solution {
public:
    //dp[i] denotes whether s[0...i-1] can be constructed
    //dp[i] = dp[i-x.size()] if x in dict
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return false;
        int len = s.length();
        vector<bool> dp (len+1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i ++) {
            for (auto x : wordDict) {
                int l = x.length();
                if (i >= l) {
                    int start = i-l;
                    if (s.substr(start, l) == x) {
                        dp[i] = dp[i] || dp[i-l];
                    }
                }
            }
        }
        
        return dp[len];
    }
};
