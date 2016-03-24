
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (auto & c : s) {
            if (m.find(c) == m.end())
                m[c] = 1;
            else
                m.erase(c);
        }
        
        return m.size() == 0 || m.size() == 1;
    }
};
