
class Solution {
public:
    //dp[i][j] denotes the maximal sum of range [i..j]
    //dp[i][j] = max{dp[i][j-1]+num[j], dp[i+1][j]+num[i]}
    //initialization: dp[i][i] = nums[i]
    //this solution is a bit wried, O(N^2) time complexity, but recall the naive solution is also O(n^2)
    int maxSubArray_2D(vector<int>& nums) {
        if (nums.empty())  
            return 0;
        int len = nums.size();
        int maxSum = 0;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < nums.size(); i ++) {
            dp[i][i] = nums[i];
            maxSum = max(maxSum, dp[i][i]);
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            for (int j = i+1; j < nums.size(); j ++) {
                dp[i][j] = max(dp[i][j-1]+nums[j], dp[i+1][j]+nums[i]);
                maxSum = max(maxSum, dp[i][j]);
            }
        }  
        return maxSum;
    }
    //the O(n) time complexity solution
    //dp[i] denotes the max subarray ending at index i (must including index i)
    //so, dp[i] = max(dp[i-1]+nums[i], nums[i])
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())  
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp (nums.size(), 0);
        
        dp[0] = nums[0];
        int maxArr = dp[0];
        for (int i = 1; i < nums.size(); i ++) {
            dp[i] = max(dp[i-1]+nums[i], nums[i]);
            maxArr = max(maxArr, dp[i]);
        }
        return maxArr;
    }
};
