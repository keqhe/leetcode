
class Solution {
public:
    //note duplicates can exist in this array
    
    //[1,1]
    //[1,3,1,1,1]
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
            
        int l = 0;
        int r = nums.size()-1;
        
        while (l <= r) {
            if (l == r) {//only 1 element in search range
                return nums[l];
            }
            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[r]) {
                r = mid;
            }
            else if (nums[mid] > nums[r]) {
                l = mid+1;
            }
            else if (nums[mid] == nums[r])
                r --;
        }
    }
};
