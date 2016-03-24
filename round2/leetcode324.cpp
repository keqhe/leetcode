
class Solution {
public:
    //the straitforward solution
    /*1, 2, 3, 4, 5 -> 3 5 2 4 1
      1 2 3 4 -> 2 4 1 3  
    */
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        sort(nums.begin(), nums.end());
        vector<int> res;
        int low = (nums.size()-1)/2;
        int high = nums.size() - 1;
        int high_count = 0;
        while (high_count < nums.size()/2) {
            res.push_back(nums[low--]);
            res.push_back(nums[high--]);
            high_count ++;
        }
        if (low >= 0)
            res.push_back(nums[low]);
        nums = res;
    }
};
