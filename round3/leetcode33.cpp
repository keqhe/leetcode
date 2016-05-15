
class Solution {
public:
    //O(n) solution is obvious
    //we are targeting O(logN) solution
    int search(vector<int>& nums, int target) {
        if (nums.empty())
            return -1;
        int l = 0;
        int r = nums.size()-1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target)
                return mid;
            if (l == r) //why we need this, think, think about test case "[1], 0"
                break;
                
            if (nums[mid] < nums[r]) { //right half (including right) is in order 
                if (nums[mid] < target && target <= nums[r]) {//we know for sure, which part we should search
                    l = mid + 1;
                }
                else {
                    r = mid -1;
                }
            }
            else if (nums[mid] > nums[r]) {//left half is in order
                if (nums[l] <= target && target < nums[mid]) {//we know for sure, which part we should search
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};
