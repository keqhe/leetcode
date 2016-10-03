
class Solution {
public:
    bool isPal(string s, int l, int r) {
        while (l < r) {
            if (s[l] != s[r])
                return false;
            l ++;
            r --;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> m;
        set<int> length;
        for (int i = 0; i < words.size(); i ++) {
            m[words[i]] = i;
            length.insert(words[i].length());
        }
        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++) {
            string curr = words[i];
            reverse(curr.begin(), curr.end());
            if (m.find(curr) != m.end() && m[curr] != i) {
                res.push_back({i, m[curr]});
            }
            int len = curr.length();
            auto len_pointer = length.find(len);
            
            //abcdd->ddcba 
            //and cba
            
            //ddcba->abcdd
            //and abc
            for (auto it = length.begin(); it != len_pointer; it ++) {
                int l = *it;
                if (isPal(curr, 0, len-l-1) && m.find(curr.substr(len-l)) != m.end()) {
                    res.push_back({i, m[curr.substr(len-l)]});
                }
                if (isPal(curr, l, len-1) && m.find(curr.substr(0, l)) != m.end()) {
                    res.push_back({m[curr.substr(0, l)], i});
                }
            }
        }
        return res;
    }
};
