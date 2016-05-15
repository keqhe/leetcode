
class Solution {
public:
    //i would call it divide and conquer
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        //first the product on itself
        for (int i = 1; i < n; i ++) {
            res[i] = res[i-1]*nums[i-1];//res[1] = 1*nums[0], res[2]=res[1]*nums[1]
        }
        //get the right half
        int multi = 1;
        for (int i = n-2; i >= 0; i --) {
            multi *= nums[i+1];
            res[i] *= multi;
        }
        
        return res;
    }
};
