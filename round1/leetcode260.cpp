
class Solution {
public:
    /*ref1: https://leetcode.com/discuss/60408/sharing-explanation-of-the-solution
    The two numbers that appear only once must differ at some bit, this is how we can distinguish between them. Otherwise, they will be one of the duplicate numbers.

    Let’s say the at the ith bit, the two desired numbers differ from each other. which means one number has bit i equaling: 0, the other number has bit i equaling 1.

    Thus, all the numbers can be partitioned into two groups according to their bits at location i. the first group consists of all numbers whose bits at i is 0. the second group consists of all numbers whose bits at i is 1.

    Notice that, if a duplicate number has bit i as 0, then, two copies of it will belong to the first group. Similarly, if a duplicate number has bit i as 1, then, two copies of it will belong to the second group.

by XoRing all numbers in the first group, we can get the first number. by XoRing all numbers in the second group, we can get the second number.
    why "diff&[~(diff - 1)] can pick one bit that is one": see https://leetcode.com/discuss/67213/how-to-use-bit-manipulation-to-solve-this-problem
    also, see:https://leetcode.com/discuss/68750/why-diff%26-diff-1-can-pick-one-bit-that-is-one
    */
    vector<int> singleNumber(vector<int>& nums) {
        int n = 0;
        for (auto & x : nums) {
            n ^= x;
        }
        //flag is the last "1" bit of n,the two elements which appear only once must be defferent in this bit
        int flag = n & ~(n-1);//
        int a = 0;
        int b = 0;
        for (auto &x : nums) {
            if (x & flag) a ^= x;
            else b ^= x;
        }
        vector<int> res;
        res.push_back(a);
        res.push_back(b);
        return res;
    }
    
    //if using hash table
    vector<int> __singleNumber(vector<int>& nums) {
        vector<int> res;
        unordered_map<int,int> ht;
        for (auto & x: nums) {
            if (ht.count(x) == 0) {
                ht[x] = 1;
            }
            else {
                ht.erase(x);
            }
        }
        
        for (auto &x : ht) {
            res.push_back(x.first);
        }
        return res;
    }
};
