
class Solution {
public:
    //dynamic programming
    //assume t[i] represents whether s[0,i-1] can be splited into words in the Dict or not
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        vector<bool> t (s.length()+1, false);
        t[0] = true;
        for (int i = 0; i < s.length(); i ++) {
            if (!t[i])
                continue;
            for (auto w : wordDict) {
                int len = w.length();
                int j = i + len;//not this is not i + len - 1 based on t's definition
                if (j > s.length())
                    continue;
                if (t[j])
                    continue;
                if (s.substr(i, len) == w)
                    t[j] = true;
            }
        }
        
        return t[s.length()];
    }
};
