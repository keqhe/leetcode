
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        if (strings.empty())
            return res;
        unordered_map<string, vector<string>> m;
        for (auto s : strings) {
            string key;
            for (int i = 0; i < s.length(); i ++) {
                if (s[i] >= s[0])
                    key += s[i] - s[0];
                else
                    key += s[i] - s[0] + 26;
            }
            m[key].push_back(s);
        }
        for (const auto& x : m) {
            res.push_back(x.second);
        }
        return res;
    }
};
