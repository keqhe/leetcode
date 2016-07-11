
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        bool flag = true;
        for (int i = 0; i+1 < nums.size(); i ++) {
            if (flag) {
                if (nums[i] > nums[i+1])
                    swap(nums[i], nums[i+1]);
            }
            else {
                if (nums[i] < nums[i+1])
                    swap(nums[i], nums[i+1]);
            }
            flag = !flag;
        }
    }
};
