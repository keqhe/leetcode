
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if (nums.empty()) {
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        
        int left = 0;
        int right = nums.size() - 1;
        int index1 = -1;
        int index2 = -1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == nums[mid]) {
                cout << "update index1" << endl;
                index1 = mid;
                right = mid - 1;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else 
                left = mid + 1;
        }
        
        //
        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (target == nums[mid]) {
                index2 = mid;
                left = mid + 1;
            }
            else if (target < nums[mid]) {
                right = mid - 1;
            }
            else 
                left = mid + 1;
        }
        
        cout << index1 << " " << index2 << endl;
        res.push_back(index1);
        res.push_back(index2);
        return res;
    }
};
