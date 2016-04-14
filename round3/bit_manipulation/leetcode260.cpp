
class Solution {
public:
    //https://github.com/keqhe/leetcode/blob/master/round2/leetcode260.cpp
    vector<int> singleNumber(vector<int>& nums) {
        int mask = 0;
        for (auto x : nums)
            mask ^= x;
        //at this point, mask = A^B
        int last = mask & (~(mask-1));//the lowest bit with value of 1 in A^B
        vector<int> res(2, 0);
        //A and B will naturally go to two different groups, think why
        for (auto x : nums) {
            if ((x & last) == 0) {
                res[0] ^= x;
            }
            else
                res[1] ^= x;
        }
        return res;
    }
};
