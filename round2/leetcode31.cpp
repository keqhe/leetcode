
class Solution {
public:
    //[2,1,3,0]
    //[2,1,4,5,3], next shoudl be [2,1,5,3,4]
    void nextPermutation(vector<int>& nums) {
        if (nums.empty() || nums.size() == 1)
            return;
        int i;
        for (i = nums.size()-2; i >= 0; i --) {
            
            if (nums[i] < nums[i+1]) {
                break;//now i is 
            }
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
        }
        else {
            sort(nums.begin()+i+1, nums.end());
            int j;
            for (j = i+1; j < nums.size(); j ++) {
                if (nums[j] > nums[i])
                    break;
            }
            swap(nums[i], nums[j]);
        }
    }
};
