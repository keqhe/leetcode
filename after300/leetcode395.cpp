
class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.empty())
            return 0;
        if (s.length() < k)
            return 0;
        unordered_map<char, int> m;
        unordered_set<char> x;
        for (auto c : s) {
            m[c] ++;
        }
        for (const auto& kv : m) {
            if (kv.second >= k) {
                x.insert(kv.first);
            }
        }
        
        string s1, s2;
        bool is_feasible = true;
        for (int i = 0; i < s.length(); i ++) {
            if (x.find(s[i]) == x.end()) {
                s1 = s.substr(0, i);
                s2 = s.substr(i+1);
                is_feasible = false;
                break;
            }
        }
        if (is_feasible)
            return s.length();
        else
            return max(longestSubstring(s1, k), longestSubstring(s2, k));
    }
};
