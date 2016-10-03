
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for (auto c : magazine) {
            m[c] ++;
        }
        for (auto c : ransomNote) {
            if (m.find(c) == m.end() || m[c] < 1)
                return false;
            m[c] --;
        }
        return true;
    }
};
