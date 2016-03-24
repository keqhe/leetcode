
class Solution {
public:
    //idea: use xor over the whole arrar, then we have res = A ^ B (because others will results in 0)
    //then use 1 single bit (the last bit to divide array into 2 groups)
    //then xor over each group, A is left in group 1, and B is in group 2
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res(2, 0);
        int r = 0;
        for (auto x : nums)
            r ^= x;
        //now number = A ^ B;
        int last = r & (~(r-1));//think about 0010, 0010 & 1110
        for (auto x : nums) {
            //if (last & x == 0) //THIS IS WRONG!!!!!
            if ((last & x) == 0)
                res[0] ^= x;
            else
                res[1] ^= x;
        }
        return res;
    }
};
