class Solution {
public:
    //see ref: https://leetcode.com/discuss/83617/java-easy-version-to-understand
    //when i is odd, we must make sure nums[i] <= nums[i+1]
    //when i is even, we must make sure nums[i] >= nums[i+1]
    void wiggleSort(vector<int>& nums) {
        for (int i = 0; i+1 < nums.size(); i ++) {
            if (i % 2 == 0) {
                if (nums[i] > nums[i+1])
                    swap(nums[i], nums[i+1]);
            }
            else {
                if (nums[i] < nums[i+1])
                    swap(nums[i], nums[i+1]);
            }
        }
    }
};
