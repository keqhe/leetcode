
class Solution {
public:
    //the following use the "last" variable technique identified by me for binary search :)
    int mySqrt_last_variable(int x) {
        int left = 0;
        int right = x/2+1;//(x/2+1)^2 > x
        
        long last = 0;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid*mid == x)
                return mid;
            else if (mid*mid < x) {
                last = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return last;
    }
    
    int mySqrt(int x) {
        int left = 0;
        int right = x/2+1;//(x/2+1)^2 > x
        while (left <= right) {
            long mid = left + (right - left) / 2;
            if (mid*mid == x)
                return mid;
            else if (mid*mid < x) {
                left = mid + 1;
            }
            else 
                right = mid - 1;
        }
        //return right;//think why returning right is okay
        return left - 1;//think why returning left-1 is also okay
    }
};
