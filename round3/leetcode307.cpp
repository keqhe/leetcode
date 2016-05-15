
//ref: https://github.com/keqhe/leetcode/blob/master/round2/leetcode307.cpp
//binary indexed tree
//two update(i) and getSum(i), both has complexity O(logN)
//first needs to construct the binary indexed tree which is O(NlogN)
class NumArray {
public:
    int size;//the size of the input arrar;
    vector<int> BIT;//the constructed binary indexed tree
    vector<int> copy;//a copy of the input array, only difference is it has size+1
    NumArray(vector<int> &nums) {
        size = nums.size();
        BIT.resize(size+1, 0);//note there, the root node of the BIT is dummy
        copy = BIT;//note copy initially has zeros, critical
        for (int i = 0; i < size; i ++) {
            update(i, nums[i]);
        }
    }

    void update(int i, int val) {//for update func, the index is of the input array
        i ++; ////note the index
        int delta = val - copy[i];
        copy[i] = val;//update the copy of the input array
        for (; i <= size; i += (i&-i)) {//i += (i&-i) is the next node to update
            BIT[i] += delta;
        }
    }
    int getSum(int i) {
        if (i < 0 || i > size) //not valid input
            return 0;
        int sum = 0;
        for (; i > 0; i -= (i&-i)) {
            sum += BIT[i];
        }
        cout << "debug getSum: " << sum << endl;
        return sum;
    }
    int sumRange(int i, int j) {
        if (i < 0 ||i >= size || j < 0 || j >= size || i > j) //not valid input
            return 0;
        int a = getSum(i);//the sum of range nums[0..i-1]
        int b = getSum(j+1);
        cout << "debug sum Range: " << b-a << endl;
        return b-a;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
