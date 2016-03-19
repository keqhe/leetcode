
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if (nums.empty())
            return res;
        int start = nums[0];
        int last = start;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] == last + 1)
                last = nums[i];
            else {
                string s;
                if (last > start)
                    s = to_string(start) + "->" + to_string(last);
                else
                    s = to_string(last);
                res.push_back(s);
                start = nums[i];
                last = start;
            }
            
            if (i == nums.size()-1) {
                string s;
                if (last > start)
                    s = to_string(start) + "->" + to_string(last);
                else
                    s = to_string(last);
                res.push_back(s);
                start = nums[i];
                last = start;
            }
        }
        if (last == nums[0]) {//not get into the loop above
            string s;
            s = to_string(last);
            res.push_back(s);
        }
        return res;
    }
};
