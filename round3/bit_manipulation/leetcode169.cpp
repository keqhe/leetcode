
class Solution {
public:
    //https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm
    int majorityElement(vector<int>& nums) {
        int candidate = 0;
        int counter = 0;
        for (int i = 0; i < nums.size(); i ++) {
            if (counter == 0) {
                candidate = nums[i];
                counter = 1;
            }
            else {
                if (candidate == nums[i])
                    counter ++;
                else
                    counter --;
            }
        }
        //check whether candidate is a real majority
        counter = 0;
        for (int i = 0; i < nums.size(); i ++)
            if (nums[i] == candidate)
                counter ++;
        if (counter > nums.size()/2)
            return candidate;
        else
            return -1;
    }
};
