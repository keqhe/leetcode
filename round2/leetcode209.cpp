
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())   
            return 0;
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = nums.size() + 1;
        for (int i = 0; i < nums.size(); i ++) {
            sum += nums[i];
            right ++;
            while (sum >= s) {
                minLen = min(right-left, minLen);
                sum -= nums[left];
                left ++;
            }
        }
        return minLen == (nums.size() + 1) ? 0 : minLen;
    }
};
