
class Solution {
public:
    int mySqrt(int x) {
        int r = x/2+1;
        int l = 0;
        while (l <= r) {
            long mid = l + (r-l)/2;
            if (mid*mid == x)
                return mid;
            else if (mid*mid < x) {
                l = mid + 1;
            }
            else 
                r = mid - 1;
        }
        return r;
    }
};
