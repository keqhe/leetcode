
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int prev = 1;
        int curr = 2;
        while (curr < nums.size()) {
            if (nums[curr] == nums[prev] && nums[prev] == nums[prev-1]) {// 3 consecutive are the same
                curr ++;
            }
            else {
                prev ++;
                nums[prev] = nums[curr];
                curr ++;
            }
        }
        return prev + 1;
    }
};
