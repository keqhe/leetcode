
class Solution {
public:
    //http://bangbingsyb.blogspot.com/2014/11/leetcode-search-in-rotated-sorted-array.html
    //duplicated elements are allowed..
    //[0, 1, 2, 3, 4]
    //[1, 2, 3, 4, 0] ; nums[mid] > nums[start] > nums[end], 
    //[2, 3, 4, 0, 1]
    /* if (target == nums[mid]) return true;
       else if (nums[start] < target < nums[mid])
          end = mid - 1;
       else start = mid + 1;
    */
    //[3, 4, 0, 1, 2] ; nums[mid] < nums[end] < nums[start]
    //[4, 0, 1, 2, 3]
    /*
        if (target == nums[mid])
            return true;
        else if (nums[mid] < target < nums[end])
            start = mid + 1;
        else
            end = mid - 1;
    */
    
    //now we have have duplicates
    /*当有重复数字，会存在A[mid] = A[end]的情况。此时右半序列A[mid-1 : end]可能是sorted，也可能并没有sorted，如下例子。

3 1 2 3 3 3 3
3 3 3 3 1 2 3

所以当A[mid] = A[end] != target时，无法排除一半的序列，而只能排除掉A[end]：

A[mid] = A[end] != target时：搜寻A[start : end-1]

正因为这个变化，在最坏情况下，算法的复杂度退化成了O(n)：
序列 2 2 2 2 2 2 2 中寻找target = 1。
*/
    bool search(vector<int>& nums, int target) {
        if (nums.empty())
            return false;
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = start + (end - start)/2;
            //cout << "mid is " << mid << endl;
            if (target == nums[mid])
                return true;
            else if (nums[mid] > nums[start]) {
                if (nums[start] <= target && target < nums[mid]) {
                    //cout << "debug 1" << endl;
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                    //cout << "debug 2" << endl;
                }
            }
            else if (nums[mid] < nums[start]) {
                if (nums[mid] < target && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
            else {//nums[mid] == nums[start]
                start ++;
            }
        }
        return false;
    }
};
