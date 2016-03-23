
class Solution {
public:
    //1, 3, 5, 0
    //0, 1, 3, 5
    //1, 3, 0, 5, 6
    //nums: 0, 1, 3, 5, 6
    //t:    0, 1, 3, 6, 9
    //t[i] = max(t[i-2] + t[i], t[i - 1])
    int rob(vector<int>& nums) {
        int * t = new int [nums.size()];
        int ret = 0;
        int i;
        for(i = 0; i < nums.size(); i ++) {
            if (i == 0)
                t[i] = nums[i];
            else if (i == 1)//initially, i made a mistake here, it must be else if...
                t[i] = max(nums[i], t[i - 1]);
            else {
                t[i] = max(t[i-2] + nums[i], t[i-1]);
            }
        }
        ret = t[nums.size() - 1];
        delete [] t;
        return ret;
    }
};
