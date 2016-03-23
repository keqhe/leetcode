
class Solution {
public:
    //when consufed by edge condiftions, think about the example; x = 5
    int helper(int x, int left, int right) {
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            unsigned long long m1 = (long)mid*mid;
            if (m1 == x ) {
                return mid;
            }
            else if (m1 < x) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return right;
    }
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        return helper(x, 1, x);
    }
};
