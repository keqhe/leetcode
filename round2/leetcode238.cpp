
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if (nums.empty())
            return res;
        res.resize(nums.size(), 1);
        for (int i = 1; i < nums.size(); i ++)
            res[i] = res[i-1]*nums[i-1];
        int multi = 1;
        for (int i = nums.size()-2; i >= 0; i --) {
            multi *= nums[i+1];
            res[i] *= multi;
        }
        return res;
    }
    /*
    class Solution {
    public:
    //ref: https://leetcode.com/discuss/70652/very-easy-two-passes-solution
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) 
            return res;
        res.resize(nums.size(), 1);
        res[0] = 1;
        //res[i] respresents the product on the left of "i"
        for (int i = 1; i < res.size(); i ++)
            res[i] = res[i-1]*nums[i-1];
        int multi = 1;
        for (int i = res.size() - 2; i >= 0; i --) {
            multi *= nums[i+1];
            res[i] *= multi;
        } 
        
        return res;
    }
};
    */
};
