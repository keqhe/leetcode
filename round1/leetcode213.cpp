
class Solution {
public:
    //the difference is that if you include 1st, you should not include the last, wise vesa
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 0)
            return 0;
        if (size == 1)
            return nums[0];
        int n = size - 1;
        vector<int> dp1(n, 0);
        vector<int> dp2(n, 0);
        
        for (int i = 0; i < size - 1; i ++) {//exculde 1st
            if (i == 0)
                dp1[i] = nums[i];
            else if (i == 1)
                dp1[i] = max(dp1[i-1], nums[i]);
            else {
                dp1[i] = max(dp1[i-1], dp1[i-2] + nums[i]);
            }
        }
        //cout << "debug1..." << endl;
        reverse(nums.begin(),nums.end());
        for (int i = 0; i < size - 1; i ++) {//exculde 1st for the reversed vector
            if (i == 0)
                dp2[i] = nums[i];
            else if (i == 1)
                dp2[i] = max(dp2[i-1], nums[i]);
            else {
                dp2[i] = max(dp2[i-1], dp2[i-2] + nums[i]);
            }
        }
        
        return max(dp1[size-2], dp2[size-2]);
    }
};
