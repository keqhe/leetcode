
class Solution {
public:
    //reference:http://www.cnblogs.com/grandyang/p/5006441.html
    //https://leetcode.com/discuss/72215/java-dp-solution-with-detailed-explanation-o-n-3
    //basic idea: let dp[i][j] denote that maximal coins we can get from i to j (inclusive)
    //then we have: dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j])
    //where i<=k<=j and we need to return dp[1][n] (why dp[i][n]?? because we insert!)
    int maxCoins(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        vector<vector<int>> dp(size+2, vector<int> (size+2, 0));
        /*
        for (int i = 1; i <= size; i ++) {
            for (int j = i; j <= size; j ++) {
                for (int k = i; k <=j; k ++) {
                    dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }*/
        
        for (int len = 1; len <= size; len ++) {
            for (int i = 1; i <= size - len + 1; i ++) {
                int j = i + len - 1;
                for (int k = i; k <= j; k ++) {
                    dp[i][j] = max(dp[i][j], nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j]);
                }
            }
        }
        
        return dp[1][size];
    }
};
