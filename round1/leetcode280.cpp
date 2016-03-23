
class Solution {
public:
    //https://leetcode.com/discuss/57120/4-lines-o-n-c
    void wiggleSort(vector<int>& nums) {
        for (int i = 1 ; i < nums.size(); i ++) {
            if ((i & 1) && nums[i] < nums[i-1] ||
                !(i & 1) && nums[i] > nums[i-1])
                swap(nums[i], nums[i-1]);
        }
    }
};
