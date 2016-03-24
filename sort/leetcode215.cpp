
class Solution {
public:
    //a nice ref: https://leetcode.com/discuss/83335/recommend-beginners-implementation-detailed-explanation
    
    //method 1, using c++ built-in function, time complexity is O(n)
    //the k-th largest elements, --> the (nums.size()-k+1) th smallest element
    int findKthLargest_built_in(vector<int>& nums, int k) {
        /*nth_element(nums.begin(), nums.begin() + nums.size()-k+1, nums.end());
        return nums[nums.size()-k+1];
        */
        nth_element(nums.begin(), nums.begin() + nums.size() - k + 1, nums.end());
        return nums[nums.size() - k + 1];
    }
    //quick sort method
    
    int partition(vector<int> & nums, int left, int right) {
        int i = left - 1;
        int j = left;
        int pivot = nums[right];
        for (; j <= right-1; j ++) {
            if (nums[j] <= pivot) {
                i ++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[right]);
        return i + 1;
    }
    void quickSort(vector<int> & nums, int left, int right) {
        if (left < right) {
            int p = partition(nums, left, right);
            quickSort(nums, left, p-1);
            quickSort(nums, p+1, right);
        }
    }
    int quickSelect(vector<int> & nums, int left, int right, int k) {
        if (left == right)
            return nums[left];
        int p = partition(nums, left, right);
        if (p == k-1)
            return nums[p];
        else if (p < k-1) 
            return quickSelect(nums, p+1, right, k);
        else
            return quickSelect(nums, left, p-1, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        if (nums.empty())
            return 0;
        /*
        quickSort(nums, 0, nums.size()-1);
        for (auto x : nums)
            cout << x << " ";
        cout << endl;
        return nums[nums.size()-k];//think about [1,2,3,4,5] and k = 3
        */
        return quickSelect(nums, 0, nums.size()-1, nums.size()-k+1);
    }
};
