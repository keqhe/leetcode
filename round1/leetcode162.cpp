
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //simple_iterate(nums);
        return binary_search(nums, 0, nums.size() - 1);
    }
    
    int binary_search(vector<int> & nums, int left, int right) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return 0;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (mid == 0 && nums[mid] > nums[mid + 1])
                return mid;
            else if (mid == nums.size() - 1 && nums[mid] > nums[mid - 1])
                return mid;
            else if (mid > 0 && mid < nums.size() - 1 && nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1])
                    return mid;
            else if (mid > 0 && nums[mid - 1] > nums[mid])
                    right = mid - 1;
            else
                    left = mid + 1;
        }
        return mid;
    }
    int simple_iterate(vector<int> & nums) {
        if (nums.size() == 0)
            return -1;
        if (nums.size() == 1)
            return 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (i == 0) {
                if (nums[0] > nums[1])
                    return 0;
            }
            else if (i == nums.size() - 1) {
                if (nums[i] > nums[i - 1])
                    return i;
            }
            
            else {
                if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
                    return i;
            }
            
        }
        return -1;
    }
};
