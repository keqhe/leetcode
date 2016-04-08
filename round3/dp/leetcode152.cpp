
class Solution {
public:
    /*let dp_min[i] denotes the min product of subarrary ending at index i (inclusive)
     dp_max[i] denote the max product of subarray ending at index i (inclusive)
     dp_min[i] = min(dp_max[i-1]*nums[i], dp_min[i-1]*nums[i],nums[i]);
     dp_max[i] = max(dp_max[i-1]*nums[i], dp_min[i-1]*nums[i], nums[i]);
     */
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];
        vector<int> dp_max(nums.size(), 0);
        vector<int> dp_min(nums.size(), 0);
        
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int maxProduct = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            int prev_dpMin = dp_min[i-1];
            int prev_dpMax = dp_max[i-1];
            dp_min[i] = min(min(prev_dpMin*nums[i], prev_dpMax*nums[i]),nums[i]);
            dp_max[i] = max(max(prev_dpMin*nums[i], prev_dpMax*nums[i]), nums[i]);
            maxProduct = max(maxProduct, dp_max[i]);
        }
        return maxProduct;
    }
};
