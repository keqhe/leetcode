
class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r = x/2+1;
        cout << "debug1" << endl;
        while (l <= r) {
            long mid = l + (r-l)/2;
            if (mid*mid == x) {
                cout << "mid is: " << mid << endl;
                return mid;
            }
            else if (mid*mid < x) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return min(l, r);
    }
};
