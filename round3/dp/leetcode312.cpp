
class Solution {
public:
    //let dp[i][j] denote the maxCoins we can get in range (i, j) (exclusive i and j)
    
    int maxCoins(vector<int>& nums) {
        if (nums.empty())
            return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        for (int len = 2; len <= size-1; len ++) {
            for (int left = 0; left + len < size; left ++) {
                int right = left + len;//len here actually mean gap
                for (int i = left+1; i < right; i ++) {
                    dp[left][right] = max(dp[left][right], dp[left][i]+dp[i][right]+nums[left]*nums[i]*nums[right]);
                }
            }
        }
        return dp[0][size-1];
    }
};
