
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> m;//value and index mapping
        for (int i = 0; i < nums.size(); i ++) {
            if (m.find(target-nums[i]) != m.end()) {
                vector<int> tmp;
                tmp.push_back(m[target-nums[i]]);
                tmp.push_back(i);
                sort(tmp.begin(), tmp.end());
                return tmp;
            }
            m[nums[i]] = i;
        }
    }
};
