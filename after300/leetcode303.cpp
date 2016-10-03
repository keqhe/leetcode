
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> &nums) {
        if (nums.empty())
            return;
        sums.resize(nums.size()+1, 0);
        for (int i = 0; i < nums.size(); i ++)
            sums[i+1] = sums[i] + nums[i];
    }

    int sumRange(int i, int j) {
        if (i < 0 || j < 0 || i > sums.size() || j > sums.size() || i > j)
            return 0;
        return sums[j+1] - sums[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
