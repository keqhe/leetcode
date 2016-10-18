
class Solution {
public:
    int partition(vector<int>& nums, int l, int r) {
        int pivot = nums[r];
        int i = l-1;
        int j = l;
        for (; j < r; j ++) {
            if (nums[j] > pivot) {
                i ++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;
    }
    int quickSelect(vector<int>& nums, int l, int r, int k) {
        if (l == r)
            return nums[l];
        int p = partition(nums, l, r);
        if (k-1 == p)
            return nums[p];
        else if (k-1 < p) {
            return quickSelect(nums, l, p-1, k);
        }
        else {
            return quickSelect(nums, p+1, r, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty())
            return -1;
        return quickSelect(nums, 0, nums.size()-1, k);
    }
};
