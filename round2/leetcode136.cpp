
class Solution {
public:
    //idea: XOR
    int singleNumber(vector<int>& nums) {
        int number = 0;
        for (auto x : nums)
            number ^= x;
        return number;
    }
};
