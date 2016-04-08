
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = -1;
        int j = 0;
        for (; j < nums.size(); j ++) {
            if (i == -1 || nums[i] != nums[j]) {
                i ++;
                nums[i] = nums[j];
            } 
        }
        return i+1;
    }
};
