
class Solution {
public:
    //method 1, use math
    //一个等差数列的和等于其首项与末项的和乘以项数除以2。
    
    //example: 0, 1, 2, 3: 
    //example: 0, 1, 2
    int missingNumber1(vector<int>& nums) {
        int l = nums.size();
        long sum = l*(l+1)/2;
        for (int i = 0; i < l; i ++) {
            sum -= nums[i];
        }
        return (int)sum;
    }
    //xor
    //    XOR properties:
    //Commutativity and Associativity, (A ^ B ^ C) ^ (A ^ B) = C
    int missingNumber(vector<int> & nums) {
        int res = 0;
        for (int i = 0; i <= nums.size(); i ++)
            res ^= i;
        for (int i = 0; i < nums.size(); i ++)
            res ^= nums[i];
        return res;
    }
    
};
