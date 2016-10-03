
class Solution {
public:
    //dp[i][j] denotes the maximum coins for range (i, j), i,j exclusive
    int maxCoins(vector<int>& nums) {
        if (nums.empty())
            return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
        for (int len = 3; len <= nums.size(); len ++) {
            for (int left = 0; left+len <= nums.size(); left ++) {
                int right = left + len - 1;
                for (int k = left+1; k < right; k ++) {
                    dp[left][right] = max(dp[left][right], dp[left][k]+dp[k][right]+nums[left]*nums[k]*nums[right]);
                }
            }
        }
        return dp[0][nums.size()-1];
    }
};
