
class Solution {
public:
    //reference: http://bangbingsyb.blogspot.com/2014/11/leetcode-next-permutation.html
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return;
        int first = numeric_limits<int>::max();
        for (int i = n - 1; i >= 1; i --) {//right to left, find the first decreasing number
            if (nums[i-1] < nums[i]) {
                first = i - 1;
                break;
            }
        }
        if (first == numeric_limits<int>::max()) {//the largest one now
            sort(nums.begin(), nums.end());
            return;
        }
        cout << "first... " << first << endl; 
        int smallest = nums[first + 1];
        int j = first + 1;
        for (int i = first + 1; i < n; i ++) {
            if (nums[i] > nums[first] && nums[i] < smallest) {
                smallest = nums[i];
                j = i;
            }
        }
        swap(nums[first], nums[j]);
        sort(nums.begin() + first + 1, nums.end());
    }
};
