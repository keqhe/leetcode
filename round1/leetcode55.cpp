
class Solution {
public:
    //[0] should return true
    bool canJump(vector<int>& nums) {
        if (nums.size() == 0)
            return false;
        //m is the maximal index we can reach till now, if m >= nums.size(), then return true;
        int m = nums[0] + 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (m <= i && nums[i] == 0 && m < nums.size() - 1)// can not reach further
                return false;
            if (i + nums[i] > m) 
                m = i + nums[i];
            if (m >= nums.size() - 1)
                return true;
        }
        return false;
    }
};
