
class Solution {
public:
    //a O(n) space solution is trival
    void myreverse(vector<int> & nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() == 1)
            return;
        k = k % nums.size();
        int a = nums.size() - k;
        myreverse(nums, 0, a-1);
        myreverse(nums, a, nums.size()-1);
        myreverse(nums, 0, nums.size()-1);
    }
};
