
class Solution {
public:
    //[1,2,3]
    //[0,1,3,6]
    int minSubArrayLen(int s, vector<int>& nums) {
        int min_size = numeric_limits<int>::max();
        int l = 0;
        int r = 0;
        int curr_sum = 0;
        while (r < nums.size()) {
            curr_sum += nums[r];
            r ++;
            while (curr_sum >= s) {
                if (r - l < min_size) {
                    min_size = r - l;
                }
                curr_sum -= nums[l];
                l ++;
            }
        }
        if (min_size == numeric_limits<int>::max())
            return 0;
        else
            return min_size;
    }
};
