
class Solution {
public:
    //ref: check rainbow post, https://leetcode.com/discuss/88717/rainbow-c-implementation
    //multiset automaticlaly sort (o(nlogn) and can use counting sort or radix sort to speed up
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty())
            return res;
        unordered_map<string, multiset<string>> m;
        for (auto s : strs) {
            string tmp = s;
            sort(tmp.begin(), tmp.end());
            m[tmp].insert(s);
        }
        
        for (auto p : m) {
            multiset<string> tmp = p.second;
            vector<string> t(tmp.begin(), tmp.end());
            res.push_back(t);
        }
        
        return res;
    }
};
