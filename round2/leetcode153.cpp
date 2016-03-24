
class Solution {
public:
    int helper(vector<int>&nums, int left, int right) {
        if (left == right)
            return nums[left];
        int mid = left + (right - left)/2;
        if (nums[mid] > nums[right])
            return helper(nums, mid+1, right);
        else
            return helper(nums, left, mid);
    }
    int findMin_mine(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
    //see ref:https://leetcode.com/discuss/45611/7-line-o-logn-solution
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            if (left == right) {
                return nums[left];
            }
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[right])//must be in right half
                left = mid + 1;
            else
                right = mid;//why not "right = mid-1"? think about [0,1]
        }
    }
};
