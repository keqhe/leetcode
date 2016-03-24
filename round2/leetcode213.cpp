
class Solution {
public:
    //ref:https://leetcode.com/discuss/82431/jave-o-1-space-o-n-time-optimal-solution
    /*Helper method returns DP solution from 0 - n-2 and 1 - n-1. Final answer is the max between two.
    */
    int helper(vector<int> & nums, int start, int end) {
        //if (start >= end)
        if (start > end)
            return 0;
        int prev2 = 0;
        int prev = nums[start];
        int curr = max(prev, prev2);
        for (int i = start+1; i <= end; i ++) {
            curr = max(prev2+nums[i], prev);
            prev2 = prev;
            prev = curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        int a = helper(nums, 0, nums.size()-2);
        int b = helper(nums, 1, nums.size()-1);
        
        return max(a, b);
    }
};
