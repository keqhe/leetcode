
class Solution {
public:
    //backtracking TLE
    void backtracking(vector<int>&nums, int curr, int target, int &res) {
        if (curr == target) {
            res ++;
        }
        if (curr > target)
            return;
        for (auto x : nums) {
            backtracking(nums, curr+x, target, res);
        }
    }
    //dp[i] denotes the number of ways for i
    //dp[i] += dp[i-x] where x is a number of nums
    //dp[0] = 0;
    //a related interesting problem: http://www.geeksforgeeks.org/dynamic-programming-set-18-partition-problem/
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i ++) {
            for (auto x : nums) {
                if (i >= x) {
                    dp[i] += dp[i-x];
                }
            }
        }
        return dp[target];
    }
};
