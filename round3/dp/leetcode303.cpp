
class NumArray {
public:
    vector<int> sums;
    //sums[i] stores the sum of nums[0..i-1]
    int size;
    NumArray(vector<int> &nums) {
        if (nums.empty())
            return;
        sums.resize(nums.size()+1, 0);
        for (int i = 1; i <= nums.size(); i ++) {
            sums[i] = sums[i-1] + nums[i-1];
        }
        size = nums.size();
    }

    int sumRange(int i, int j) {
        if (i < 0 || i >= size || j < 0 || j >= size || i > j)
            return 0;
        int a = sums[i];
        int b = sums[j+1];
        return b-a;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
