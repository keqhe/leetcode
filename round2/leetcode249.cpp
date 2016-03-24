
class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> res;
        if (strings.empty())
            return res;
        multiset<string> test;
        
        unordered_map<string, multiset<string>> m;
        for (auto s : strings) {
            string tmp = s;
            if (tmp.empty())
                m[""].insert(tmp);
            else {
                char start = tmp[0];
                for (int i = 0; i < tmp.length(); i ++) {
                    if (tmp[i] >= start)
                        tmp[i] -= start;
                    else    
                        tmp[i] = tmp[i]+26-start;
                }
                
                m[tmp].insert(s);
            }
        }
        
        for (auto p : m) {
            multiset<string> t = p.second;
            vector<string> tmp(t.begin(), t.end());
            res.push_back(tmp);
        }
        return res;
    }
};
