
class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        vector<int> dp1(nums.size(), 1);//dp1[i], ending at i, pos
        vector<int> dp2(nums.size(), 1);//dp2[i], ending at i, neg
        int max_pos = 1;
        int max_neg = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > nums[i-1]) {
                dp1[i] = max_neg + 1;
                max_pos = max(max_pos, dp1[i]);
            }
            else if (nums[i] < nums[i-1]) {
                dp2[i] = max_pos + 1;
                max_neg = max(max_neg, dp2[i]);
            }
            else {
                continue;
            }
        }
        return max(max_pos, max_neg);
    }
};
