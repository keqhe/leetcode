
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    //[bad]
    //[good, bad]
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid;
        while (left <= right) {
            mid = left + (right - left)/2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (right < mid)
            return mid;
        if (mid < left)
            return left;
    }
};
