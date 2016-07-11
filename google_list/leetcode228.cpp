
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty())
            return res;
        if (nums.size() == 1) {
            string tmp = to_string(nums[0]);
            res.push_back(tmp);
            return res;
        }
        int begin = nums[0];
        int last = nums[0];
        for (int i = 1; i < nums.size(); i ++) {
            int curr = nums[i];
            if (i == nums.size()-1) {
                if (curr > last + 1) {
                    if (last > begin) {
                        string tmp = to_string(begin) + "->" + to_string(last);
                        res.push_back(tmp);
                    }
                    else {
                        string tmp = to_string(begin);
                        res.push_back(tmp);
                    }
                    string tmp = to_string(curr);
                    res.push_back(tmp);
                }
                else {
                    string tmp = to_string(begin) + "->" + to_string(curr);
                    res.push_back(tmp);
                }
            }
            else {
                if (curr > last+1) {
                    if (last > begin) {
                        string tmp = to_string(begin) + "->" + to_string(last);
                        res.push_back(tmp);
                    }
                    else {
                        string tmp = to_string(begin);
                        res.push_back(tmp);
                    }
                    begin = curr;
                    last = curr;
                }
                else {
                    last = curr;
                }
            }
        }
        return res;
    }
};
