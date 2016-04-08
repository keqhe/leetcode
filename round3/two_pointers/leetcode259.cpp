
class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int total = 0;
        for (int i = 0; i < nums.size(); i ++) {
            int j = i+1;
            int k = nums.size()-1;
            while (j < k) {
                if (nums[i]+nums[j]+nums[k] < target) {//all k's within [j+1, k] works
                    total += k-j;
                    j ++;
                }
                else {
                    k --;
                }
            }
        }
        return total;
    }
};
