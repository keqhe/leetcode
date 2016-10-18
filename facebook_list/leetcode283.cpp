
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;
        while (j < nums.size()) {
            while (j+1 < nums.size() && nums[j] == 0)
                j ++;
            swap(nums[i++], nums[j++]);
        }
    }
};
