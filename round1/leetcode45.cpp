
class Solution {
public:
    //ref: http://bangbingsyb.blogspot.com/2014/11/leetcode-jump-game-i-ii.html
    //Jump Game 1 and Jump Game II
    int jump(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int curMax = 0;
        int n = 0;//num of jumps
        int i = 0;
        while (curMax < nums.size() - 1) {
            int lastMax = curMax;
            for (; i <= lastMax; i ++)
                curMax = max(curMax, i+nums[i]);
            n ++;
            if (curMax == lastMax)
                return -1;
        }
        return n;
    }
};
