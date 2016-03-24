
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 3)
            return nums.size();
        
        int i = 0;
        int j = 0;
        int dup = 0;
        while (j < nums.size()) {
            if (j > 0 && nums[j] == nums[j-1])
                dup ++;
            else
                dup = 0;//reset dup counter to 0, think about test case [1,1,2,2]
            if (dup == 2) {
                while (j > 0 && nums[j] == nums[j-1])
                    j ++;
                dup = 0;
            }  
            if (j < nums.size())
                nums[i++] = nums[j++];
        }
        return i;
    }
};
