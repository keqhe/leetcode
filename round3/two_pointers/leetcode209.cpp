
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int l = 0;
        int r = 0;
        int minLen = numeric_limits<int>::max();
        int sum = 0;
        while (r < nums.size()) {
            sum += nums[r];
            r ++;
            while (sum >= s) {
                if (r - l < minLen) {
                    minLen = min(minLen, r-l);
                }
                sum -= nums[l];
                l ++;
            }
        }
        return minLen == numeric_limits<int>::max() ? 0 : minLen;
    }
};
