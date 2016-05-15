
class Solution {
public:
    //this is easier to understand, 
    //https://github.com/keqhe/leetcode/blob/master/round1/leetcode45.cpp
    int jump(vector<int>& nums) {
        if (nums.empty())
            return 0;
        //let currMax denote the max index we can reach after each step
        int currMax = 0;
        int n = 0;//the min step needed
        int i = 0;
        while (currMax < nums.size()-1) {
            int lastMax = currMax;
            for (; i <= lastMax; i ++)
                currMax = max(currMax, i+nums[i]);
            n ++;
            if (currMax == lastMax)
                return -1;//not able to reach the last one
        }
        return n;
    }
};
