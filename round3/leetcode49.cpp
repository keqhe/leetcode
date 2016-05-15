
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, multiset<string>> m;
        
        for (auto x : strs) {
            string tmp = x;
            sort(tmp.begin(), tmp.end());
            m[tmp].insert(x);
        }
        
        vector<vector<string>> res;
        for (auto kv : m) {
            string k = kv.first;
            multiset<string> v = kv.second;
            vector<string> t (v.begin(), v.end());
            res.push_back(t);
        }
        return res;
    }
};
