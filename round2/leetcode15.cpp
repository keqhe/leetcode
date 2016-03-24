
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.empty())
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if ((nums[i] + nums[left] + nums[right]) == 0) {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);
                    
                    while (left < right && nums[left] == nums[left+1])
                        left ++;
                    left ++;
                    while (left < right && nums[right] == nums[right-1])
                        right --;
                    right --;
                }
                else if ((nums[i] + nums[left] + nums[right]) < 0) {
                    while (left < right && nums[left] == nums[left+1])
                        left ++;
                    left ++;
                }
                else {
                    while (left < right && nums[right] == nums[right-1])
                        right --;
                    right --;
                }
            }
        }
        return res;
    }
};
