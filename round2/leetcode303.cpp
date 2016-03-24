
class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int> &nums) {
        sums.resize(nums.size(), 0);
        
        int acc = 0;
        for (int i = 0; i < nums.size(); i ++) {
            sums[i] = acc + nums[i];
            acc = sums[i];
        }
    }

    int sumRange(int i, int j) {
        if (i > j || i < 0 || j > sums.size()-1)
            return 0;
        if (i - 1 >= 0)
            return sums[j] - sums[i-1];
        else
            return sums[j];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
