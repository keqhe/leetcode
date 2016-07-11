
class Solution {
public:
    //TLE
    bool wordBreak1(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return false;
        for (auto w : wordDict) {
            if (s == w)
                return true;
            if (s.length() >= w.length() && s.substr(0, w.length()) == w) {
                if (wordBreak(s.substr(w.length()), wordDict))
                    return true;
            }
        }
        return false;
    }
    
    //DFS or backtracking TLE
    //This problem uses DP
    //let dp[i] denotes whether s[0..i-1] can be break into words in wordDict
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())  
            return false;
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i ++) {
            for (auto w : wordDict) {
                int len = w.length();
                if (i >= len) {
                    if (s.substr(i-len, len) == w) {
                        dp[i] = dp[i] || dp[i-len];
                    }
                }
            }
        }
        return dp[s.length()];
    }
};
