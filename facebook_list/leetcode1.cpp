
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> m;
    
        for (int i = 0; i < nums.size(); i ++) {
            int curr = nums[i];
            if (m.find(target - curr) != m.end()) {
                res.push_back(m[target-curr]);
                res.push_back(i);
                return res;
            }
            m[curr] = i;
        }
        return res;
    }
};
