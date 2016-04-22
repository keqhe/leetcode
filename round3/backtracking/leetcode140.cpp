
class Solution {
public:
    //let dp[i][j] denote the possible sentences of s[i...j]
    //dp[i][j] = dp[i][k] + dp[k+1][j], this may work
    
    //method 2, dfs with cache or  recursion with cache, this is also called memeorization or DP
    vector<string> dfs(string s, unordered_set<string> & wordDict, unordered_map<string, vector<string>> &m) {
        if (m.find(s) != m.end())
            return m[s];
        vector<string> res;
        if (s.empty())
            return res;
        for (auto w : wordDict) {
            int len = w.length();
            if (s == w) {
                res.push_back(w);
            }
            else if (s.substr(0, len) == w) {
                vector<string> left = dfs(s.substr(len), wordDict, m);
                for (auto x : left) {
                    res.push_back(w + " " + x);
                }
            }
        }
        m[s] = res;
        return res;
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.empty())
            return res;
        unordered_map<string, vector<string>> m;
        return dfs(s, wordDict, m);
    }
};
