
class Solution {
public:
    //first, using a hash table is easy
    
    //method 2 is XOR (^)
    int missingNumber(vector<int>& nums) {
        int a = 0;
        for (int i = 0; i <= nums.size(); i ++)
            a ^= i;
        for (auto x : nums)
            a ^= x;
        return a;
    }
};
