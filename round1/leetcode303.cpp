
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> &nums) {
        int size = nums.size();
        sums.resize(size+1, 0);
        for (int i = 0; i < size; i ++) {
            sums[i+1] = sums[i] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if (j < i)
            return 0;
        return sums[j+1] - sums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
