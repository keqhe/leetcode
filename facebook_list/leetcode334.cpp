
class Solution {
public:
    //我们遍历数组，维护一个最小值，和倒数第二小值，遍历原数组的时候，如果当前数字小于等于最小值，更新最小值，如果小于等于倒数第二小值，更新倒数第二小值，如果当前数字比最小值和倒数第二小值都大，说明此时有三个递增的子序列了，直接返回ture
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
