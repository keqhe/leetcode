
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty())
            return res;
        if (nums.size() == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int start = nums[0];
        int prev = start;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] == prev+1) {
                if (i+1 == nums.size()) {
                    string tmp = to_string(start) + "->" + to_string(nums[i]);
                    res.push_back(tmp);
                    break;
                }
                else
                    prev = nums[i];
            }
            else {
                if (i+1 == nums.size()) {
                    string tmp;
                    if (prev != start)
                        tmp = to_string(start) + "->" + to_string(prev);
                    else
                        tmp = to_string(start);
                    res.push_back(tmp);
                    res.push_back(to_string(nums[i]));
                    break;
                }
                else {
                    string tmp;
                    if (prev != start)
                        tmp = to_string(start) + "->" + to_string(prev);
                    else
                        tmp = to_string(start);
                    res.push_back(tmp);
                    start = nums[i];
                    prev = start;
                }
            }
        }
        return res;
    }
};
