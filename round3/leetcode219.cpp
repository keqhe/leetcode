
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if (nums.empty())
            return false;
        unordered_map<int, int> m;//value, index
        for (int i = 0; i < nums.size(); i ++) {
            if (m.find(nums[i]) != m.end()) {
                int curr = i - m[nums[i]];
                if (curr <= k)
                    return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};
