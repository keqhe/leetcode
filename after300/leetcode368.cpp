
class Solution {
public:
    //ref: https://discuss.leetcode.com/topic/49528/python-dp-n-2-solution
    //dp[i] denotes the largest divisible subset ending at index i
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.empty())
            return {};
        vector<vector<int>> dp(nums.size(), vector<int>());
        sort(nums.begin(), nums.end());
        dp[0] = {nums[0]};
        for (int i = 1; i < nums.size(); i ++) {
            vector<int> maxSet;
            for (int j = 0; j < i; j ++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j].size()+1 > maxSet.size()) {
                        maxSet = dp[j];
                    }
                }
            }
            maxSet.push_back(nums[i]);
            dp[i] = maxSet;
        }
        vector<int> res;
        for (auto x : dp) {
            if (x.size() > res.size())
                res = x;
        }
        return res;
    }
};
