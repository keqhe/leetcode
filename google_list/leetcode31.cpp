
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int found = false;
        int j;
        for (int i = 0; i+1 < nums.size(); i ++) {
            if (nums[i] < nums[i+1]) {
                found = true;
                j = i;
            }
        }
        if (found) {
            int i = j+1;
            int min_index = i;
            int min_value = nums[i];
            for (; i < nums.size(); i ++) {
                //if (nums[i] < min_value) {// WRONG! nums[i] shoud > nums[j]!!
                if (nums[i] < min_value && nums[i] > nums[j]) {
                    min_index = i;
                    min_value = nums[i];
                }
            }
            swap(nums[j], nums[min_index]);
            sort(nums.begin()+j+1, nums.end());
        }
        else {
            sort(nums.begin(), nums.end());
        }
    }
};
