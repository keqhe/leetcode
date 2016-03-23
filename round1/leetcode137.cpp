
class Solution {
public:
    //https://leetcode.com/discuss/31595/detailed-explanation-generalization-bitwise-operation-numbers
    //all other ints appear exactly k times (k > 1), except for 1 who appear p times (p>=1 and p % k != 0)
    //we need m >= logk (int) counters, say xm..x1
    //k = pm..p1. 
    //return xj of pj == 1
    //k = 3 in this case, so m = 2, k = 11, so return either x1 or x2 is fine
    int singleNumber(vector<int>& nums) {
        int x1 = 0;
        int x2 = 0;
        int mask;
        for (int i = 0; i < nums.size(); i++) {
            x2 = x2 ^ (x1 & nums[i]);
            x1 = x1 ^ nums[i];
            mask = ~(x1 & x2);
            
            x2 = x2 & mask;
            x1 = x1 & mask;
        }
        return x1;
    }
};
