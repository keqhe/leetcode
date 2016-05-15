
class Solution {
public:
    //the last variable technique with binary search
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.empty())
            return res;
        int l = 0;
        int r = nums.size()-1;
        
        int last = -1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (nums[mid] == target) {
                last = mid;
                r = mid - 1;
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        
        res.push_back(last);
        
        l = 0;
        r = nums.size() -1;
        last = -1;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (nums[mid] == target) {
                last = mid;
                l = mid + 1;
            }
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid - 1;
        }
        res.push_back(last);
        
        return res;
    }
    
};
