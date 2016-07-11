
class Solution {
public:
    //[4,5,5,6]
    //[1,2,3,4,5,6,7]
    //[1,1,1,4,5,6]
    void wiggleSort(vector<int>& nums) {
        if (nums.empty())
            return;
        sort(nums.begin(), nums.end());
        int i = (nums.size()-1)/2;
        int j = nums.size()-1;
        
        vector<int> tmp(nums.size(), 0);
        int k = 0;
        while (i >= 0 && j > (nums.size()-1)/2) {
            tmp[k++] = nums[i--];
            tmp[k++] = nums[j--];
        }
        if (nums.size() % 2 != 0)
            tmp[k] = nums[i];
        nums = tmp;
    }
};
