
class Solution {
public:
    //let dp[i][j] denote the max number of coins we can get for range (i,,j) {i and j are exclusive}
    int maxCoins(vector<int>& nums) {
        if (nums.empty())
            return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int size = nums.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        for (int len = 3; len <= size; len ++) {
            for (int l = 0; l+len <= size; l ++) {
                int r = l + len - 1;
                for (int i = l+1; i < r; i ++) {
                    //ballon i is the last one to burst
                    int local = dp[l][i] + dp[i][r] + nums[l]*nums[i]*nums[r];
                    dp[l][r] = max(dp[l][r], local);
                }
            }
        } 
        return dp[0][size-1];
    }
};
