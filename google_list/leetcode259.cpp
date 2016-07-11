
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        int total = 0;
        //if you do not want to sort, are you kidding me?
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
                int curr = nums[i] + nums[l] + nums[r];
                if (curr >= target) {
                    r --;
                }
                else if (curr < target) {
                    total += r - (l+1) + 1;
                    l ++;
                }
            }
        }
        return total;
    }
};
