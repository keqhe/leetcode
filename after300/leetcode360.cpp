
class Solution {
public:
    //https://discuss.leetcode.com/topic/48424/java-o-n-incredibly-short-yet-easy-to-understand-ac-solution
    int func(int x, int a, int b, int c) {
        return a*x*x + b*x + c;
    }
    //insight needed: 
    //when a >= 0, the two sides are larger than then the middle
    //when a < 0, middles are larger than the two sides
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        if (nums.empty())
            return {};
        vector<int> sorted(nums.size(), 0);
        int i = 0;
        int j = nums.size()-1;
        int index;
        if (a >= 0) {
            index = nums.size()-1;
        }
        else {
            index = 0;
        }
        while (i <= j) {
            if (a >= 0) {
              int left_side = func(nums[i], a, b, c);
              int right_side = func(nums[j], a, b, c);
              if (left_side >= right_side) {
                sorted[index] = left_side;
                i ++;
              }
              else {
                sorted[index] = right_side;
                j --;
              }
              index --;
            }
            else {
              int left_side = func(nums[i], a, b, c);
              int right_side = func(nums[j], a, b, c);
              if (left_side <= right_side) {
                sorted[index] = left_side;
                i ++;
              }
              else {
                sorted[index] = right_side;
                j --;
              }
              index ++; 
            }
        }
        return sorted;
    }
};
