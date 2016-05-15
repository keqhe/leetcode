
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int l = 0;
        int r = nums.size()-1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (l == r)
                return nums[l];
                
            if (nums[mid] < nums[r]) {
                r = mid; //this is important
            }
            else if (nums[mid] > nums[r]) {
                l = mid + 1;
            }
        }
    }
};
