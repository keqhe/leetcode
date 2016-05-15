
class Solution {
public:
    //the following is wrong, think why using test case: [5,9,3,2,1,0,2,3,3,1,0,0]
    bool canJump_WRONG(vector<int>& nums) {
       if (nums.empty())
        return false;
       int i = 0;
       
       while (i < nums.size()) {
           if (i+nums[i] >= nums.size()-1)
            return true;
           int maxIndex = i;
           for (int j = i; j <= i+nums[i]; j ++) {
               maxIndex = max(maxIndex, j+nums[j]);
           }
           if (maxIndex == i)
            break;
           i = maxIndex;
           if (i >= nums.size()-1)
            return true;
       }
       return false;
    }
    //the version below is better than round 2
    //time complexity is O(n)
    bool canJump(vector<int>& nums) {
        if (nums.empty())
            return false;
        //let x denote the max index we can reach
        int x = 0;//we start from index 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (x >= nums.size()-1)
                return true;
            if (x < i)
                return false;
            if (i+nums[i] > x) {
                x = i + nums[i];
                if (x >= nums.size()-1)
                    return true;
            }
        }
        return false;
    }
};
