
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> index;
        for (int i = 0; i < nums.size(); i ++) {
            if (index.find(target - nums[i]) != index.end()) {
                res.push_back(index[target-nums[i]]);
                res.push_back(i);
                return res;
            }
            if (index.find(nums[i]) == index.end())
                index[nums[i]] = i;
        }
    }
};
