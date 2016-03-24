
class Solution {
public:
    //seems to be hard one
    //ref: https://leetcode.com/discuss/72216/share-some-analysis-and-explanations
    //ref: https://leetcode.com/discuss/85862/16-ms-dp-c-solution-beating-96%25-others
    //the key idea is to analyze what is the last bubble to burst?
    //dp[i][j] denotes the maxCoins we can get to burst balloons between (i...j),
    //note exculding i and j, 
    int maxCoins(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<vector<int>> dp(nums.size()+2, vector<int>(nums.size()+2, 0));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        
        int size = nums.size();
        for (int len = 2; len <= size-1; len ++) {//think about the base case [1,3,1]
            for (int left = 0; left + len < size; left ++) {
                int right = left + len;
                for (int i = left+1; i < right; i ++) {
                    //balloon i is the last ballon to burst in range(i,j)
                    int local = dp[left][i]+dp[i][right]+nums[left]*nums[i]*nums[right];
                    dp[left][right] = max(dp[left][right], local);
                }
            }
        }
        
        return dp[0][size-1];
    }
};
