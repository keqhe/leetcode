
class Solution {
public:
    //ref: https://leetcode.com/discuss/75176/java-easy-to-read
    string makeRange(int s, int e) {
        if (s == e)
            return to_string(s);
        else 
            return to_string(s) + "->" + to_string(e);
    }
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        if (nums.empty()) {
            res.push_back(makeRange(lower, upper));
            return res;
        }
        for (auto & n : nums) {
            if (n > upper)
                break;
            if (n < lower)
                continue;//still need to go further
            else if (lower < n) {
                res.push_back(makeRange(lower, n-1));
                lower = n + 1;
            }
            else if (lower == n) {
                lower = n + 1;
            }
        }
        //take care of the last "gap" if it exists
        int last = nums[nums.size()-1];
        if (upper > last)
            res.push_back(makeRange(last+1, upper));
        return res;
    }
};
