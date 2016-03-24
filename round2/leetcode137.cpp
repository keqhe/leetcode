
class Solution {
public:
    //https://leetcode.com/discuss/31595/detailed-explanation-generalization-bitwise-operation-numbers
    //an array, each number appear k times, except for 1, which appears p times where 1 <= p < k;
    int singleNumber(vector<int>& nums) {
        int x2 = 0;
        int x1 = 0;
        int mask = 0;
        for (auto & x : nums) {
            x2 ^= x1 & x;
            x1 ^= x;
        
            mask = ~(x2 & x1);
            x2 &= mask;
            x1 &= mask;
        }
        
        return x1;
    }
};
