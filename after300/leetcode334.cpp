
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)
            return false;
        //https://discuss.leetcode.com/topic/37577/my-accepted-java-solution-for-this-question-only-7-lines-clear-and-concise
        int Min = numeric_limits<int>::max();
        int secondMin = numeric_limits<int>::max();
        for (auto x : nums) {
            if (x <= Min) Min = x;
            else if (x <= secondMin)
                secondMin = x;
            else if (x > secondMin)
                return true;
        }
        return false;
    }
};
