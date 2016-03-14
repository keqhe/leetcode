
class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int left = lower-1;//notice here
        if (nums.empty()) {
            string t;
            if (lower < upper)
                t = to_string(lower) + "->" + to_string(upper);
            else if (lower == upper)
                t = to_string(lower);
            res.push_back(t);
            return res;
        }
        for (int i = 0; i < nums.size(); i ++) {
            int curr = nums[i];
            if (left+1 < curr-1) {
                string tmp =  to_string(left+1) + "->" + to_string(curr-1);
                res.push_back(tmp);
            }
            else if (left+1 == curr-1) {
                string tmp = to_string(left+1);
                res.push_back(tmp);
            }
            left = curr;
        }
        if (nums.back()+1 < upper) {
            res.push_back(to_string(nums.back()+1)+"->"+to_string(upper));
        }
        else if (nums.back()+1 == upper) {
             res.push_back(to_string(nums.back()+1));
        }
        return res;
    }
};
