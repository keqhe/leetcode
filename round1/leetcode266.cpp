
class Solution {
public:
    //ref: https://leetcode.com/discuss/53295/java-solution-w-set-one-pass-without-counters
    bool canPermutePalindrome(string s) {
        unordered_set<char> se;
        for (auto & c : s) {
            if (se.find(c) == se.end()) 
                se.insert(c);
            else 
                se.erase(c);
        }
        return se.size() == 0 || se.size() == 1;
    }
};
