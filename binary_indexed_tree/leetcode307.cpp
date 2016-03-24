
class NumArray {
public:
    //ref: look at round1's implemetation
    //ref: fenwick or binary indexed tree explained: https://www.youtube.com/watch?v=CWDQJGaN1gY
    //ref: https://github.com/mission-peace/interview/blob/master/src/com/interview/tree/FenwickTree.java
    int size;//the size of the input array
    vector<int> BIT;
    vector<int> copy; //a copy of the orginal input array
    NumArray(vector<int> &nums) {
        size = nums.size();
        BIT.resize(size+1, 0);//in BIT, the number of nodes is size+1 (root is dummy)
        copy = BIT;
        for (int i = 0; i < nums.size(); i ++)
            update(i, nums[i]);
    }

    void update(int i, int val) {
        int delta = val - copy[++i];//note the ++i, it is not i, think why
        copy[i] = val; //copy is filled up here
        /*i += (i & -i) is the method to get the node we want to update next */
        for (; i <= size; i += (i & -i)) {
            BIT[i] += delta;
        }
    }
    int getSum(int i) {
        if (i <= 0 || i > size) {
            // i == 0 is the root of the binary indexed tree
            // the max index of the binary indexed tree is size
            return 0;
        }
        int sum = BIT[i];
        while ( (i -= (i & -i)) > 0) {//i -= (i & -i) is the method to get the parent of a node
            sum += BIT[i];
        }
        return sum;
    }
    int sumRange(int i, int j) {
        if (i < 0 || i >= size || j < 0 || j >= size || i > j)
            return 0;
        if (i == j)
            return copy[i+1];//note it is i+1, not i, think why
        int a = getSum(i);//this gives us the sum of range [0..i-1] of the orginal array
        int b = getSum(j+1);//
        return b-a;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
