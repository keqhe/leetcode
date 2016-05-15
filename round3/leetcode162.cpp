
class Solution {
public:
    //O(n) method is easy
    //what about O(logN)
    
    //according to the problem description, there is no duplicated elements
    int findPeakElement(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if ( (mid == 0 || nums[mid] > nums[mid-1]) && 
                 (mid == nums.size()-1 || nums[mid] > nums[mid+1]))
                return mid;
            else if (nums[mid] < nums[mid+1])
                l = mid + 1;
            else if (nums[mid] < nums[mid-1])
                r = mid - 1;
        }
        
    }
};
