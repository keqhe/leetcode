
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        long diff = numeric_limits<long>::max();
        int res;
        for (int i = 0; i < nums.size(); i ++) {
            int j = i + 1;
            int k = nums.size()-1;
            while (j < k) {
                if (nums[i]+nums[j]+nums[k] == target) {
                    return target;
                }
                else if (nums[i]+nums[j]+nums[k] < target) {
                    if (abs(nums[i]+nums[j]+nums[k]-target) < diff) {
                        res = nums[i]+nums[j]+nums[k];
                        diff = abs(nums[i]+nums[j]+nums[k]-target);
                    }
                    j ++;
                }
                else {
                    if (abs(nums[i]+nums[j]+nums[k]-target) < diff) {
                        res = nums[i]+nums[j]+nums[k];
                        diff = abs(nums[i]+nums[j]+nums[k]-target);
                    }
                    k --;
                }
            }
        }
        return res;
    }
};
