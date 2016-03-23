
class Solution {
public:
    //O(nlogn) solution
    int __maximumGap(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        sort(nums.begin(), nums.end());
        int gap = 0;
        for (int i = 1; i < nums.size(); i ++) {
            int diff = nums[i] - nums[i-1];
            gap = max(gap, diff);
        }
        return gap;
    }
    //O(n), radix sort which uses couting sort (which is stable sort)
    //ref: https://leetcode.com/discuss/53636/radix-sort-solution-in-java-with-explanation
    //O(d*(n+k)) where k = 9 in this case and is at most ~10
    vector<int> radixSort(vector<int> & nums) {
        if (nums.size() <= 1)
            return nums;
        int base = 1; //1, 10, 100, 1000...
        vector<int> B(nums.size());
        int m = 0; //max in the nums vector
        for (auto x: nums) {
            m = max(m, x);
        }
        while (m / base > 0) {//go through all digits, from LSB to MSB
            vector<int> C(10);
            for (int i = 0; i < nums.size(); i ++) {
                int digit = (nums[i]/base) % 10;
                C[digit] += 1;
            }
            for (int i = 1; i < 10; i ++) {
                C[i] = C[i] + C[i-1];
            }
            
            for (int i = nums.size() - 1; i >= 0; i --) {
                int digit = (nums[i]/base) % 10;
                int pos = --C[digit];
                B[pos] = nums[i];
            }
            
            for (int i = 0; i < nums.size(); i ++)
                nums[i] = B[i];
            base *= 10;
            
        }
        return B;
    }
    int maximumGap(vector<int>& nums) {
        if (nums.size() <= 1)
            return 0;
        vector<int> tmp = radixSort(nums);
        int gap = 0;
        for (int i = 1; i < tmp.size(); i ++) {
            int diff = tmp[i] - tmp[i-1];
            gap = max(gap, diff);
        }
        return gap;
        
    }
};
