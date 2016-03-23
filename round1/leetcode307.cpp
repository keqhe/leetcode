
class NumArray {
public:
    //ref1: http://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/
    //ref2: https://leetcode.com/discuss/70793/short-binary-indexed-tree-fenwick-tree-based-solution-1720
    //key is O(logN) for both sumRange and update
    vector<int> BIT;
    int size;//size of input array
    vector<int> num;//copy of input array
    NumArray(vector<int> &nums) {
        size = nums.size();
        BIT = vector<int>(size+1, 0);
        num = BIT;
        for (int i = 0; i < size; i ++)
            update(i, nums[i]);
    }

    void update(int i, int val) {
        int delta = val - num[++i];
        for(num[i] = val;i<= size;i += i & -i)
            BIT[i] +=delta;
    }

    int sumRange(int i, int j) {//[i,j]
        if ( i < 0 || i > size || j < 0 || j > size || i > j)
            return 0;
        if (i == j)
            return num[i+1];
            
        int a = getSum(i) ;// sum of [0: i-1]
        int b = getSum(j+1);// sum of [0: j];
        return b - a;
    }
    int getSum(int i) {//get the sum of the first i element in the original array
        if (i <= 0 || i > size)
            return 0;
        int res = BIT[i];
        
        while ((i -= i & -i) > 0) {//the parent of i is (i - i & -i)
            res += BIT[i];
        }
        return res;
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);
