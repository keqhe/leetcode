
class Solution {
public:
    //ref: https://leetcode.com/discuss/67417/my-16ms-c-code
    //O(n^3)?
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        //[1,2,3,4]
        for (int i = 0; i <= nums.size() - 4; i ++) {
            if (i > 0 && nums[i] == nums[i-1])
                continue;//avoid duplicates
            for (int j = i + 1; j <= nums.size() - 3; j ++) {
                if (j > i + 1 && nums[j] == nums[j-1])
                    continue;
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    if (nums[i] + nums[j] + nums[left] + nums[right] == target) {
                        vector<int> tmp;
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
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
                    else if (nums[i] + nums[j] + nums[left] + nums[right] < target) {
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
        }
        return res;
    }
};
