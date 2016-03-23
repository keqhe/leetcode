
class Solution {
public:
    //http://bangbingsyb.blogspot.com/2014/11/leecode-find-minimum-in-rotated-sorted.html
    //[1,2,3]
    //[2,1,3]
    //when nums[mid] < nums[right] ==> mid shoud be in [left, mid]
    //when nums[mid] > nums[right] ==> min should be in [mid+1, right]
    //return nums[left], think about [2, 1] as an example and [1, 2] as another

    int findMin(vector<int> & nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
        }
        return nums[left];
    }
    //below is mine solution
    int findMin_mine(vector<int>& nums) {
        
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (mid == 0) {
                if (nums[mid+1] > nums[mid])
                    return nums[mid];
                else
                    left = mid + 1;
            }
            else if (mid == nums.size() - 1) {
                if (nums[mid-1] > nums[mid])
                    return nums[mid];
                else
                    right = mid - 1;
            }
            else {
                if (nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1])
                    return nums[mid];
                else if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) {//where I should search?
                    if (nums[mid] > nums[right])
                        left = mid + 1;
                    else
                        right = mid - 1;
                }
                //else if (nums[mid] < nums[mid-1] && nums[mid] > nums[mid+1]) //never happen
                else if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                    return nums[mid + 1];
            }
        }
    }
};
