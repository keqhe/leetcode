
class NumArray {
public:
    //lanyue Lu met this problem
    //binary indexed tree (BIT)
    int size; //vector size
    vector<int> copy;
    vector<int> BIT;
    NumArray(vector<int> &nums) {
        if (nums.empty())
            return;
        size = nums.size();
        BIT.resize(size+1, 0);
        copy = BIT;
        for (int i = 0; i < nums.size(); i ++) {
            update(i, nums[i]);
        }
    }
    void update(int i, int val) {
        i ++;
        int delta = val - copy[i];
        copy[i] = val;
        for (; i <= size; i += (i & -i)) {
            BIT[i] += delta;
        }
    }
    
    int getSum(int i) {
        if (i <= 0 || i > size)
            return 0;
        int sum = 0;
        for (; i > 0; i -= (i&-i)) {
            sum += BIT[i];
        }
        return sum;
    }
    int sumRange(int i, int j) {
        if (i < 0 || i >= size || j < 0 || j >= size || i > j)
            return 0;
        int a = getSum(i);
        int b = getSum(j+1);
        return b-a;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
