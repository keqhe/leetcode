
class Solution {
public:
    //dp_max[i] = max(dp_max[i-1]*nums[i], dp_min[i-1]*nums[i], nums[i])
    //dp_min[i] = min(dp_max[i-1]*nums[i], dp_min[i-1]*nums[i], nums[i])
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int len = nums.size();
        vector<int> dp_max(len, 0);
        vector<int> dp_min(len, 0);
        
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        
        int Max = dp_max[0];
        for (int i = 1; i < len; i ++) {
            dp_max[i] = max(max(dp_max[i-1]*nums[i], dp_min[i-1]*nums[i]), nums[i]);
            dp_min[i] = min(min(dp_max[i-1]*nums[i], dp_min[i-1]*nums[i]), nums[i]);
            
            Max = max(Max, dp_max[i]);
        }
        
        return Max;
    }
};
