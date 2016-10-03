
class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 1;
        int r = num/2+1;//r*r > num
        while (l <= r) {
            long mid = l + (r-l)/2;
            if (mid*mid == num)
                return true;
            else if (mid*mid < num) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return false;
    }
};
