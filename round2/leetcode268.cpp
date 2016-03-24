
class Solution {
public:
    //idea: XOR
    int missingNumber(vector<int>& nums) {
        int number = 0;
        int maxNum = nums.size();
        for (int i = 0; i <= nums.size(); i ++)
            number ^= i;
        for (auto x : nums)
            number ^= x;
        return number;
    }
};
