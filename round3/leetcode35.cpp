
class Solution {
public:
    //no duplicates in this problem
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target) {
                l = mid + 1;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
        }
        
        return l;
    }
    
    //the last variable trick can also work here
};
