
class Solution {
public:
    //O(n) solution is to use sliding window, 
    //IDEA: for each i (starting at index i), I find the subarray that has a sum >= s; 
    //once find one, then I move left index to right
    //reference:http://zwzbill8.blogspot.com/2015/05/leetcode-minimum-size-subarray-sum.html
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty())
            return 0;
        int total = 0;
        for (auto x : nums)
            total += x;
        if (total < s)
            return 0;
        int left = 0;//that is index i in IDEA
        int right = 0;
        int sum = nums[0];
        int lenMin = numeric_limits<int>::max();
        while (right < nums.size()) {
            if (sum < s) {
                right ++;
                sum += nums[right];
            }
            else {
                if (lenMin > right - left + 1)
                    lenMin = right - left + 1;
                sum -= nums[left];
                left ++;
            }
        }
        
        return lenMin;
    }
};
