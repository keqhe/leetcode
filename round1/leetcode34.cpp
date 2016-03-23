
class Solution {
public:
    //reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-search-for-range.html
    //find leftmost, then right most, binary search
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int a = leftMost(nums, target);
        int b = rightMost(nums, target);
        res.push_back(a);
        res.push_back(b);
        return res;
    }
    
    int leftMost(vector<int> & nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int found = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                found = mid;
                right = mid -1;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        
        return found;
    }
    
    int rightMost(vector<int> & nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int found = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] == target) {
                found = mid;
                left = mid + 1;
            }
            else if (nums[mid] > target) {
                right = mid -1;
            }
            else {
                left = mid + 1;
            }
        }
        return found;
    }
};
