
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> se;
        for (auto c : s) {
            if (se.find(c) == se.end()) {
                se.insert(c);
            }
            else {
                se.erase(c);
            }
        }
        return se.size() == 0 || se.size() == 1;
    }
};
