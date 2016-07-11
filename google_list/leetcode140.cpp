
class Solution {
public:
    //memorization, dp
    vector<string> dfs(string s, unordered_set<string>& wordDict, unordered_map<string, vector<string>> & cache) {
        if (cache.find(s) != cache.end())
            return cache[s];
        vector<string> res;
        for (auto w : wordDict) {
            if (s == w) {
                /*cache[s] = {w};
                return {w};*/ // this is WRONG, can not return here!!! think why
                res.push_back(w);
            }
            else {
                if (s.length() > w.length() && s.substr(0, w.length()) == w) {
                    vector<string> leftover = dfs(s.substr(w.length()), wordDict, cache);
                    for (auto s : leftover) {
                        res.push_back(w+' '+ s);
                    }
                }
            }
        }
        cache[s] = res;
        return res;
    }
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        vector<string> res;
        if (s.empty() || wordDict.empty())
            return res;
        unordered_map<string, vector<string>> cache;
        res = dfs(s, wordDict, cache);
        return res;
    }
};
