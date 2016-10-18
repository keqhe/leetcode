
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int i = -1;
        int j = 0;
        int counter = 0;
        while (j < nums.size()) {
            if (i== -1 || i == 0) {
                nums[++i] = nums[j++];
            }
            else {
                if (nums[i] == nums[i-1]) {
                    if (nums[j] == nums[i]) {
                        j ++;
                        continue;
                    }
                    else
                        nums[++i] = nums[j++];
                }
                else {
                    nums[++i] = nums[j++];
                }
            }
        }
        return i+1;
    }
};
