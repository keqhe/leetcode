
class Solution {
public:
    //first, an O(nlogn) solution found at https://leetcode.com/discuss/76965/3-lines-python-with-explanation-proof
    //idea: put smaller half at even indexes and bigger half at odd indexes
    //example, even number: nums = [1, 2, 3, 4, 5, 6, 7, 8], so the answer should be [4,8,3,7,2,6,1,5]
    /* why this is correct? M means Medium, same value
        M   S   S   S (dec)
          L   M   M   M (incr)
    */
    void __wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        sort(nums.begin(), nums.end());
        vector<int> tmp (nums.size(), 0);
        int i = (nums.size() -1) / 2;
        int j = nums.size() - 1;
        for (int k = 0; k < tmp.size(); k ++) {
            if (k % 2 == 0) {
                tmp[k] = nums[i--];
            }
            else {
                tmp[k] = nums[j--];
            }
        }
        
        nums = tmp;
    }
    //an O(n) solution using three-way-partition algorithm
    //ref1: https://leetcode.com/discuss/77085/clean-average-o-n-time-in-c
    //ref2: https://leetcode.com/discuss/77115/o-n-time-o-1-space-solution-with-detail-explanations
    //ref3: https://en.wikipedia.org/wiki/Dutch_national_flag_problem#Pseudocode
    
    //i feel the references' definition on median is wrong....
    void wiggleSort(vector<int>& nums) {
        if (nums.size() <= 1)
            return;
        vector<int> tmp (nums.size());
        vector<int>::iterator median = next(nums.begin(), (nums.size()-1)/2);
        nth_element(nums.begin(), median, nums.end());//the element specified by median is in correct place
        int mid = nums[(nums.size()-1)/2];
        
        threeWayPartition(nums, mid);
        
        int largeStart = nums.size() - 1;
        int smallStart = (nums.size()-1)/2;
        for (int i = 0; i < tmp.size(); i += 2) {//even indexes
            tmp[i] = nums[smallStart--];
        }
        
        for (int i = 1; i < tmp.size(); i += 2) {//odd indexes
            tmp[i] = nums[largeStart--];
        }
        
        nums = tmp;
    }
    
    void threeWayPartition(vector<int> & nums, int mid) {
        int i = 0;
        int j = 0;
        int k = nums.size() -1;
        while (j <= k) {
            if (nums[j] < mid)
                swap(nums[i++], nums[j++]);
            else if (nums[j] > mid)
                swap(nums[j++], nums[k--]);
            else
                j ++;
        }
    }
};
