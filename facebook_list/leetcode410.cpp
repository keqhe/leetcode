
class Solution {
public:
    //https://discuss.leetcode.com/topic/61324/clear-explanation-8ms-binary-search-java
    bool doable(long mid, vector<int>&nums, int m) {
        long acc = 0;
        int count = 1;
        for (auto x : nums) {
            acc += x;
            if (acc > mid) {
                acc = x;
                count ++;
                if (count > m)
                    return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int max_val = numeric_limits<int>::min();
        long sum = 0;
        for (auto x : nums) {
            sum += x;
            max_val = max(max_val, x);
        }
        if (m == 1)
            return sum;
        long l = max_val;
        long r = sum;
        while (l <= r) {
            long mid = l + (r-l)/2;
            if (doable(mid, nums, m)) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return static_cast<int>(l);
    }
};
