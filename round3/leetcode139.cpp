
class Solution {
public:
    //backtracking TLE for a test case
    bool backtracking(string s, unordered_set<string>& wordDict) {
        for (auto w : wordDict) {
            int len = w.length();
            if (w == s)
                return true;
            if (len < s.length()) {
                if (s.substr(0, len) == w) {
                    if (backtracking(s.substr(len), wordDict))
                        return true;
                }
            }
        }
        return false;
    }
    bool wordBreak_backtracking(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return false;
        return backtracking(s, wordDict);
    }
    //dp, https://github.com/keqhe/leetcode/blob/master/round2/leetcode139.cpp
    //dp[i] denotes whether s[0..i-1] can be constructed
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        if (s.empty() || wordDict.empty())
            return false;
        int len = s.length();
        vector<bool> dp(len+1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i ++) {
            for (auto w : wordDict) {
                int l = w.length();
                if (i >= l && s.substr(i-l, l) == w)
                    dp[i] = dp[i] | dp[i-l];
            }
        }
        return dp[len];
    }
};
