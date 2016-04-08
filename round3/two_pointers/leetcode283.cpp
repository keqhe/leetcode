
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty())
            return;
        int i = -1;
        int j = 0;
        for (; j < nums.size(); j ++) {
            if (nums[j] != 0) {
                i ++;
                swap(nums[i], nums[j]);
            }
        }
    }
};
