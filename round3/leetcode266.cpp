
class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_set<char> us;
        for (auto c : s) {
            if (us.find(c) == us.end())
                us.insert(c);
            else
                us.erase(c);
        }
        return us.size() == 0 || us.size() == 1;
    }
    //other thoughts, you can sort it...
};
