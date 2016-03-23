
class Solution {
public:
    //binary search, O(n) is to restore the array first
    //but O(logN), the key is to  know after it is rotated, half is still sorted.
    //assuming, we are trying to search for 0
    //case 1: [4, 5, 6, 7, 0, 1, 2], left half is sorted
    //case 2: [6, 7, 0, 1, 2, 4, 5] ,right half is sorted
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[left] <= nums[mid]) {//left hard is sorted
                if (nums[left] <= target && target < nums[mid])
                    right = mid - 1;
                else 
                    left = mid + 1;
            }
            else if (nums[left] > nums[mid]) {//right half is sorted
                if (nums[mid] < target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
