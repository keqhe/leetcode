
class Solution {
public:
    //greedy
    //http://www.cnblogs.com/grandyang/p/5165821.html
    
    int minPatches(vector<int>& nums, int n) {
        int i = 0;
        long miss = 1;
        int added = 0;
        while (miss <= n) {
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
