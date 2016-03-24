
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int dist = numeric_limits<int>::max();
        int res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size()-3; i ++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (abs(target - (nums[i] + nums[left] + nums[right])) < dist) {
                    dist = abs(target - (nums[i] + nums[left] + nums[right]));
                    res = nums[i] + nums[left] + nums[right];
                }
                if (nums[i] + nums[left] + nums[right] == target) {
                    return res;
                }
                else if (nums[i] + nums[left] + nums[right] < target) {
                    while (left < right && nums[left] == nums[left+1])
                        left ++;
                    left ++;
                }
                else {
                    while (left < right && nums[right] == nums[right-1])
                        right --;
                    right --;
                }
            }
        }
        return res;
    }
};
