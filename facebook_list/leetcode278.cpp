
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1;
        int r = n;
        while (l < r) {
            int mid = l + (r - l)/2;
            if (isBadVersion(mid))
                r = mid;
            else l = mid + 1;
        }
        
        return (isBadVersion(l) ? l : r);
    }
    
    int firstBadVersion3(int n) {
        int l = 1;
        int r = n;
        int res = 0;
        while (l <= r) {
            int mid = l + (r - l)/2;
            if (isBadVersion(mid)) {
                res = mid;
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return res;
    }
};
