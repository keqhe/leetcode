
class Solution {
public:
    //dp[i] = max(dp[i-2] + nums[i], dp[i-1])
    //if you include the first one, you must NOT include the last one
    //so find the max for [0...n-2] and [1...n-1] and return the max of these two max values
    
    int helper(vector<int> & nums) {
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size()-1; i ++) {
            dp[i] = max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[nums.size()-2];
    }
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int a = helper(nums);
        reverse(nums.begin(), nums.end());
        int b = helper(nums);
        return max(a, b);
    }
};
