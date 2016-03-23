
class Solution {
public:
    //[1,3,5,6], key = 2, left = 0, right = 3
    //mid = 1, left = 0, right = 0
    //mid = 0, left = 1, right = 0;
    
    //[1,3,5,6], key = 7, left = 0, right = 3
    //mid = 1, left = 2, right = 3;
    //mid = 2, left = 3, right = 3;
    //mid = 3, left = 4, right = 3;
    
    //[1,3,5,6], key = 0, left = 0, right = 3
    //mid = 1, left = 0, right = 0;
    //mid = 0, left = 0, right = -1;
    int binarySearch(vector<int> & nums, int key, int left, int right) {
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == key)
                return mid;//found
            else if (nums[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        //not found
        return left;
    }
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};
