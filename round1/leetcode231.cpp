
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1)
            return true;
        if (n < 2 && n != 1)
            return false;
            
        while(n>=2) {
            if (n % 2 != 0)
                return false;
            n = n / 2;
        }
        if (n == 1)
            return true;
        else
            return false;
    }
};
