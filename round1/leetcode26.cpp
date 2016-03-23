
// [1, 1]
// [1, 1, 1]
// [1, 1, 1, 2, 2]
class Solution {
public:
    //ref
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int i = 0;
        int j = 1;
        while (j < nums.size()) {
            if (nums[i] == nums[j]) {
                j ++;
            }
            else {
                i ++;
                nums[i] = nums[j];
                j ++;
            }
        }
        return i + 1;
    }
    
    int removeDuplicates_mine(vector<int>& nums) {
        int i = nums.size() - 1;
        while (nums.size() > 1) {//<=1 no need to process 
            if((i - 1) >= 0) {
                if (nums[i] == nums[i-1]) {
                    nums.erase(nums.begin() + i);
                }
                i --;
            }
            else 
                break;
        }
        return nums.size();
    }
};
