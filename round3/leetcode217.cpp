
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for (auto x : nums) {
            if (us.find(x) != us.end())
                return true;
            else
                us.insert(x);
        }
        return false;
    }
};
