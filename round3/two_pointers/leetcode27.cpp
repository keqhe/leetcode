
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = -1;
        int j = 0;
        for (; j < nums.size(); j ++) {
            if (nums[j] != val) {
                i ++;
                nums[i] = nums[j];
            }
        }
        return i+1;
    }
};
