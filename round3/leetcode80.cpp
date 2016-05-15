
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int i = -1;
        int j = 0;
        while (j < nums.size()) {
            if (i == -1) {
                nums[++i] = nums[j];
                j ++;
            } 
            else if (i >= 0) {
                if (nums[i] != nums[j]) {
                    nums[++i] = nums[j];
                    j ++;
                }
                else {
                    if (i-1 < 0 || nums[i-1] != nums[j]) {
                        nums[++i] = nums[j];
                        j ++;
                    }
                    else {
                        j ++;
                    }
                }
            }
        }
        return i + 1;
    }
};
