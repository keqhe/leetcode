
class Solution {
public:
    bool containsNearbyDuplicate2(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i + 1; j < nums.size(); j ++) {
                if (nums[i] == nums[j] && abs(i - j) <= k)
                    return true;
            }
        }
        return false;
    }
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i ++) {
            if (map.find(nums[i]) == map.end()) {//no entry yet
                map[nums[i]] = i;
            }
            else {//found
                int delta = abs (map[nums[i]] - i);
                map[nums[i]] = i;
                if  (delta <= k)
                    return true;
            }
        }
        return false;
    }
};
