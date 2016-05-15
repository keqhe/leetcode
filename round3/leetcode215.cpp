
class Solution {
public:
    //quick select
    int partition(vector<int>&nums, int l, int r) {
        int pivot = nums[r];
        int i = l-1;
        int j = l;
        for (; j <= r-1; j ++) {
            if (nums[j] <= pivot) {
                i ++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[r]);
        return i+1;//now (i+1)th element must at proper place
    }
    int quickSelect(vector<int>&nums, int l, int r, int k) {
        if (l == r)
            return nums[l];
        int p = partition(nums, l, r);
        if (p == k-1)
            return nums[p];
        else if (p < (k - 1))
            return quickSelect(nums, p+1, r, k);
        else 
            return quickSelect(nums, l, p-1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k+1);//1,2,3,4
    }
};
