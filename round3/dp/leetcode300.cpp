
class Solution {
public:
    //let dp[i] denotes the length of LIS ending at nums[i] (ie, must include nums[i])
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
          return 0;
        vector<int> dp(nums.size(), 1); //?
        int maxLen = 1;
        for (int i = 0; i < nums.size(); i ++) {
          for (int j = 0; j < i; j ++) {
            if (nums[i] > nums[j]) {
              if (dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
              //dp[i] = max(dp[i], dp[j]+1);
            }
          }
        }
        for (int i = 0; i < nums.size(); i ++)
            maxLen = max(maxLen, dp[i]);
        return maxLen;
    }
};
