
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (lower > upper)
            return res;
        if (nums.empty()) {
            if (lower == upper)
                res.push_back(to_string(lower));
            else
                res.push_back(to_string(lower)+"->"+to_string(upper));
            return res;
        }
        //first possible gap
        if (lower < nums[0]) {
            if (lower+1 == nums[0])
                res.push_back(to_string(lower));
            else 
                res.push_back(to_string(lower) + "->" + to_string(nums[0]-1));
        }
        int left = nums[0]+1;
        for (int i = 1; i < nums.size(); i ++) {
            if (left == nums[i]) {
                left = nums[i] + 1;
            }
            else if (left < nums[i]) {
                if (left + 1 < nums[i]) {
                    res.push_back(to_string(left)+"->"+to_string(nums[i]-1));
                }
                else if (left+1 == nums[i]) {
                    res.push_back(to_string(left));
                }
                left = nums[i] + 1;
            }
        }

        
        if (nums[nums.size()-1] < upper) {
            if (nums[nums.size()-1] + 1 == upper)
                res.push_back(to_string(upper));
            else 
                res.push_back(to_string(nums[nums.size()-1]+1) + "->" + to_string(upper));
        }
        return res;
    }
};
