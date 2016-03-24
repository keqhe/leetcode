
class Solution {
public:
    //ref:https://leetcode.com/discuss/66857/the-correct-dp-solution
    int rob__(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
            
        vector<int> dp(nums.size()+1, 0);
        dp[0] = 0;
        dp[1] = nums[1-1];
        
        for (int i = 2; i <= nums.size(); i ++) {
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        
        return dp[nums.size()];
    }
    //ref:https://leetcode.com/discuss/85651/my-dp-o-n-time-o-1-space-solution
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        int prepre_money = 0;
        int pre_money = nums[0];
        int money;
        for (int i = 1; i < nums.size(); i ++) {
            money = max(prepre_money+nums[i], pre_money);
            prepre_money = pre_money;
            pre_money = money;
        }
        
        return money;
        
    }
};
