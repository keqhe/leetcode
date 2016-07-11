
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        if (strings.empty())
            return res;
        unordered_map<string, vector<string>> m;
        for (auto str : strings) {
            if (str.empty()) {
                m[""].push_back(str);
            }
            else {
                string s;
                char c = str.front();
                for (auto x : str) {
                    int index = x-c;
                    if (index < 0)
                        index += 26;
                    s.push_back(index+'a');
                }
                m[s].push_back(str);
            }
        }
        
        for (auto kv : m) {
            res.push_back(kv.second);
        }
        return res;
    }
};
