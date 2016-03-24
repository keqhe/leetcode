
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        unordered_map<int, int> m;
        for (auto & x : nums) {
            if (m.find(x) == m.end())
                m[x] ++;
            else
                return true;
        }
        return false;
    }
};
