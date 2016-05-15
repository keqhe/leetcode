
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i ++) {
            if (i>0 && nums[i] == nums[i-1])
                continue;
            for (int j = i+1; j < nums.size(); j ++) {
                //if (j-1>=0 && nums[j] == nums[j-1])////WRONG, think why
                if (j>i+1 && nums[j] == nums[j-1])
                    continue;
                int p = j+1;
                int q = nums.size()-1;
                while (p < q) {
                    if (nums[i]+nums[j]+nums[p]+nums[q] == target) {
                        vector<int> tmp = {nums[i], nums[j], nums[p], nums[q]};
                        res.push_back(tmp);
                        while (q < q && nums[p+1] == nums[p])
                            p ++;
                        p ++;
                        while (p < q && nums[q-1] == nums[q])
                            q --;
                        q --;
                    }
                    else if (nums[i]+nums[j]+nums[p]+nums[q] < target) {
                        p ++;
                    }
                    else {
                        q --;
                    }
                    
                }
            }
        }
        return res;
    }
};
