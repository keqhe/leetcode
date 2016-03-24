
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return nums.size();
        int i = 0;
        int j = 0;
        int len = nums.size();
        while (j < len-1) {
            while (nums[j] == nums[j+1]) {
                j ++;
            }
            nums[i++] = nums[j++];
        }
        if (j == len-1)
            nums[i++] = nums[j++];
            
        return i;
    }
};
