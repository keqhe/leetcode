class Solution {
public:
    //see ref: https://leetcode.com/discuss/83272/share-my-thinking-process
    //ref: https://leetcode.com/discuss/82822/solution-explanation
    int minPatches(vector<int>& nums, int n) {
        long miss = 1;//[1..miss) are reachable
        int i = 0;
        int added = 0;
        while (miss <= n) {//why <= n and not < n, think why
            if (i < nums.size() && nums[i] <= miss) {
                miss += nums[i];
                i ++;
            }
            else {
                miss += miss;
                added ++;
            }
        }
        return added;
    }
};
