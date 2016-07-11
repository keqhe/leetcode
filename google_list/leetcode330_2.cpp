
class Solution {
public:
    //greedy
    //http://www.cnblogs.com/grandyang/p/5165821.html
    
    int minPatches(vector<int>& nums, int n) {
        if (n == 0)
            return 0;
        long maxNum = 0;
        int i = 0;
        int added = 0;
        while (maxNum < n) {
            if (i < nums.size() && nums[i] <= maxNum+1) {
                maxNum += nums[i];
                i ++;
            }
            else {
                maxNum += maxNum + 1;
                added ++;
            }
        }
        return added;
    }
};
