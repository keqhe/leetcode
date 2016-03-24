
class Solution {
public:
    //ref: https://leetcode.com/discuss/73779/my-116ms-c-dp-solution
    //ref2: https://leetcode.com/discuss/86140/c-simple-dp-solution
    //dp[i] denote the length of LIS in nums[0...i] with nums[i] as the ending element
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int len = nums.size();
        int maxLen = 1;
        vector<int> dp(len, 1);
        for (int i = 0; i < len; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};
