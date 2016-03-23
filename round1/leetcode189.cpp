
class Solution {
public:
    //O(1) extra space, O(nk)
    void rotate1(vector<int>& nums, int k) {
        if (nums.size() == 0)
            return;
        for (int i = 1; i <= k; i ++) {
            int a = nums.back();
            nums.insert(nums.begin(), a);//O(n)
            nums.pop_back();
        }
    }
    //O(n) extra space, 2*n copy, O(n) time complexity
    void rotate2(vector<int> & nums, int k) {
       
        if (nums.size() == 0)
            return;
        vector<int> v (nums.size(), 0);
        for (int i = 0; i < nums.size(); i ++) {
            int j = (i + k) % nums.size();
            v[j] = nums[i];
        }
        nums = v;
    }
    
    void rotate(vector<int> & nums, int k) {
        k = k % nums.size();
        if (k == 0 || nums.size() == 0)
            return;
        reverse(nums.begin(), nums.end()); // 0 to n -1
        reverse(nums.begin(), nums.begin() + k);// 0 to k -1
        reverse(nums.begin() + k, nums.end());
    }
};
