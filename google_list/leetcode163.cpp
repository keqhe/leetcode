
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (nums.empty()) {
            if (lower == upper) {
                string tmp = to_string(lower);
                res.push_back(tmp);
                return res;
            }
            else {
                string tmp = to_string(lower) + "->" + to_string(upper);
                res.push_back(tmp);
                return res;
            }
        }
        //first possible gap
        if (lower < nums[0]) {
            if (lower == nums[0]-1) {
                string tmp = to_string(lower);
                res.push_back(tmp);
            }
            else if (lower < nums[0]-1) {
                string tmp = to_string(lower) + "->" + to_string(nums[0]-1);
                res.push_back(tmp);
            }
        }
        
        int last = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            int curr = nums[i];
            if (curr-1 == last) {
                last = curr;
            }
            else if (curr-1 > last) {
                if (curr-1 == last+1) {
                    string tmp = to_string(last+1);
                    res.push_back(tmp);
                }
                else if (curr-1 > last+1) {
                    string tmp = to_string(last+1) + "->" + to_string(curr-1);
                    res.push_back(tmp);
                }
                last = curr;
            }
        }
        if (nums[nums.size()-1] < upper) {
            if (nums[nums.size()-1] == upper-1) {
                string tmp = to_string(upper);
                res.push_back(tmp);
            }
            else if (nums[nums.size()-1] < upper-1) {
                string tmp = to_string(nums[nums.size()-1]+1) + "->" + to_string(upper);
                res.push_back(tmp);
            }
        }
        return res;
    }
};
