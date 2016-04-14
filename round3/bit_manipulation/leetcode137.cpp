
class Solution {
public:
    //a hash table solution is easy
    
    //what about bit manipulation, k = 3 and p = 1
    int singleNumber(vector<int>& nums) {
        int x2 = 0;
        int x1 = 0;
        int mask = 0;
        for (auto x : nums) {
            x2 ^= x1 & x;
            x1 ^= x;
            mask = ~(x2 & x1);
            
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
    }
};
