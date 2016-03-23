
class Solution {
public:
    //reference: https://leetcode.com/discuss/61837/a-clean-c-solution-with-unordered_map
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> m;
        
        for (auto &s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            m[key].push_back(s);
        }
        
        for (auto & inst : m) {
            sort(inst.second.begin(), inst.second.end());
            res.push_back(inst.second);
        }
        
        return res;
    }
};
