
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int count = 0;
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i <= nums.size() - 3; i ++) {
            /*if (i > 0 && nums[i] == nums[i-1])
                continue;
            */
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] >= target) {
                    /*while (left < right && nums[right] == nums[right-1])
                        right --;
                    */
                    right --;
                }
                else {
                    count += right - left;
                    left ++;
                }
            }
        }
        return count;
    }
};
