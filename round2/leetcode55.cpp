
class Solution {
public:
    //ref: https://leetcode.com/discuss/90757/a-simple-c-answer
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        if (nums.size() == 1)
            return true;
        int Max = nums[0];
        for (int i = 0; i < nums.size(); i ++) {
            if (i > Max) {
                return false;
            }
            if (nums[i] + i > Max)
                Max = nums[i] + i;
            if (Max >= nums.size()-1)
                return true;
        }
        return true;
    }
};
