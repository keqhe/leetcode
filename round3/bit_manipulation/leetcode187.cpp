
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        if (s.length() < 10)
            return res;
        unordered_map<string, int> m;
        for (int i = 0; i + 10 <= s.length(); i ++) {
            string str = s.substr(i, 10);
            m[str] ++;
        }
        
        for (auto kp : m) {
            if (kp.second > 1) {
                res.push_back(kp.first);
            }
        }
        return res;
    }
};
