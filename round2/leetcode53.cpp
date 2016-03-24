
class Solution {
public:
    //dp[i] denotes the max sub array ending at index i
    //dp[i] = max(dp[i-1]+nums[i], nums[i])
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int len = nums.size();
        vector<int> dp(len, 0);
        dp[0] = nums[0];
        int Max = dp[0];
        for (int i = 1; i < len; i ++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            Max = max(Max, dp[i]);
        }
        
        return Max;
    }
};
