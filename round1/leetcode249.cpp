
bool mycmp(string s1, string s2) {
    if (s1.length() < s2.length())
        return s1.length() < s2.length();
    else 
        return s1 < s2;
}
class Solution {
public:
    unordered_map<string, vector<string>> m;
    string getKey(string s) {
        int offset = s[0] - 'a';
        string key;
        for (auto & c : s)
            key += (c - offset + 26) % 26 + 'a';
        return key;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        sort(strings.begin(), strings.end());
        
        for (auto & s : strings) {
            m[getKey(s)].push_back(s);
        }
        
        vector<vector<string>> res;
        for (auto & d : m) {
            res.push_back(d.second);
        }
        return res;
    }
};
