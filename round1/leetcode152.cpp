
class Solution {
public:
    //ref1: http://www.programcreek.com/2013/02/leetcode-maximum-subarray-java/
    //ref2: http://www.programcreek.com/2014/03/leetcode-maximum-product-subarray-java/
    //ref3: http://bangbingsyb.blogspot.com/2014/11/leetcode-maximum-product-subarray.html
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int localMin = nums[0];
        int localMax = nums[0];
        int res = nums[0];
        
        for (int i = 1; i < nums.size(); i ++) {
            int temp = localMin;//error prone...
            localMin = min(nums[i], min(localMin*nums[i], localMax*nums[i]));
            localMax = max(nums[i], max(temp*nums[i], localMax*nums[i]));
            
            if (res < localMax)
                res = localMax;
        }
        
        return res;
    }
};
