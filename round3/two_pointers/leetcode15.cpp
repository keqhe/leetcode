
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            if (i-1 >=0 && nums[i] == nums[i-1])//de-dup logic
                continue;
            int j = i + 1;
            int k = nums.size()-1;
            while (j < k) {
                if (nums[i] + nums[j] + nums[k] == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    tmp.push_back(nums[k]);
                    res.push_back(tmp);
                    while (j+1 < nums.size() && nums[j] == nums[j+1])//de-dup logic
                        j ++;
                    j ++;
                    while (k-1 >= 0 && nums[k] == nums[k-1]) //de-dup logic
                        k --;
                    k --;
                }
                else if (nums[i] + nums[j] + nums[k] < 0) {
                    j ++;
                }
                else {
                    k --;
                }
            }
        }
        return res;
    }
};
