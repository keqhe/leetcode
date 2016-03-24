
class Solution {
public:
    //https://leetcode.com/discuss/72640/my-clean-c-code-8ms-easy-understanding
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int left = 1;
        int right = 1000000;//2147483647
        //take x = 5 as an example
        while (left <= right) {
            long mid = left + (right - left)/2;
            if (mid * mid == x) {
                return mid;
            }
            else if (mid*mid > x) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return right;
    }
};
