
class Solution {
public:
    //let dp[i] denote the length of LIS ending at index i
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        vector<int> dp(nums.size(), 1);
        int maxLen = 1;
        dp[0] = 1;
        for (int i = 1; i < nums.size(); i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                    maxLen = max(dp[i], maxLen);
                }
            }
        }
        return maxLen;
    }
};
