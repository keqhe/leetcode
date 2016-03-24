
class Solution {
public:
    //while an O(n) solution is quite simple
    //the efficient algorithm is O(N) and O(1)
    void myreverse(vector<int> & nums, int left, int right) {
        while (left < right) {
            swap(nums[left++], nums[right--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || nums.size() == 1 || (k % nums.size()) == 0)
            return;
        
        k = k % nums.size();
        int a= nums.size() - k;
        
        myreverse(nums, 0, a-1);//reverse the first part
        myreverse(nums, a, nums.size()-1);//reverse the second part;
        myreverse(nums, 0, nums.size()-1);//reverse the whole array
    }
};
