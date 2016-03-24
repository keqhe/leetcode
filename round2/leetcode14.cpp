
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty())
            return "";
        int minLen = numeric_limits<int>::max();
        for (auto s : strs) {
            minLen = min(minLen, (int)s.length());
        }
        
        if (minLen == 0)
            return "";
        string res;
        for (int j = 0; j < minLen; j ++) {
            bool same = true;
            char c = strs[0][j];
            for (int i = 1; i < strs.size(); i ++) {
                if (strs[i][j] != strs[i-1][j])
                    return res;
            }
            res.push_back(c);
        }
        
        return res;
    }
};
