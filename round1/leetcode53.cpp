
class Solution {
public:
    //d[i] = max(nums[i], d[i-1]+nums[i])
    //d[i] means the maximal value ending with index i
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        int mymax = nums[0];
        vector<int> dp(size, 0);
        
        dp[0] = nums[0];
        for(int i = 1; i < size; i ++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            if (mymax < dp[i])
                mymax = dp[i];
        }
        return mymax;
    }
};
