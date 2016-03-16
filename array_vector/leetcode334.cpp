
class Solution {
public:
    //ref: https://leetcode.com/discuss/87204/accepted-java-solution-this-question-only-lines-clear-concise
    bool increasingTriplet(vector<int>& nums) {
      if (nums.size() < 3)
        return false;
      long Min = numeric_limits<long>::max();//minimal number so far
      long secondMin = numeric_limits<long>::max();//second minimal number so far
      for (auto x : nums) {
          if (x <= Min) //must be <=, think why
            Min = x;
          else if (x <= secondMin)
            secondMin = x;
          else if ( x > secondMin)
            return true;
      }
      return false;
    }
};
