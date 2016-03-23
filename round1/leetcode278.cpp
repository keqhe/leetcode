
//[1]
//[0]
//[0, 0, 1]
//[0, 0, 1, 1]
//[0, 1, 1]
// Forward declaration of isBadVersion API.

//int mid = (left + right) / 2 is WRONG because of overflow?
bool isBadVersion(int version);

class Solution {
public:
/*
    int helper(unsigned long long int left, unsigned long long int right) {
        unsigned long long int mid = (left + right) / 2;
        if (left == right)
            return right;
        if (right > left) {
            if (isBadVersion(mid))
                return helper(left, mid);
            else 
                return helper(mid+1, right);
        }
    }
    int firstBadVersion2(int n) {
        if (n == 1) {
            if (isBadVersion(n) == 1)
                return n;
            else
                return 0;
        }
        else { //n >= 2
            unsigned long long int mid = n / 2;
            if (isBadVersion(mid) == 1) {
                return helper(1, mid);
            }
            else {
                return helper(mid+1, n);
            }
        }
    }
    */
    int firstBadVersion(int n) {
        long left = 1;
        long right = n;
        if (!isBadVersion(n))
            return 0;
            
        while (left <= right) {
            if (left == right)
                return right;
            long mid = (left + right) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            }
            else
                left = mid + 1;
        }
    }
     //ref
     int firstBadVersion5(int n) {
        int begin = 1;
        int end = n;
        int mid;
        int firstBad = n;
        while(begin <= end)
        {
                mid = begin + ( end - begin) / 2;
                if(isBadVersion(mid))
                {
                        firstBad = mid;
                        end = mid - 1;
                }
                else
                {
                        begin = mid + 1;
                }
        }

        return firstBad;
    }
};
