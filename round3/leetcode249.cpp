
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        //unordered_map<string, set<string>> m;
        unordered_map<string, multiset<string>> m;//duplicated value may exists
        for (auto s : strings) {
            if (s.empty())
                m[""].insert(s);
            else {
                char c = s[0];
                string key;
                for (int i = 0; i < s.length(); i ++)
                    key.push_back(s[i]>=c ? (s[i]-c):(s[i]+26-c));//az  ba
                m[key].insert(s);
                
            }
        }
        for (auto kv : m) {
            vector<string> tmp(kv.second.begin(), kv.second.end());
            res.push_back(tmp);
        }
        return res;
    }
};
